/******** DO NOT EDIT THIS FILE ********/
#ifndef _SEM_IPCJOBQUEUE_H
#define _SEM_IPCJOBQUEUE_H
#include <stdbool.h>
#include <semaphore.h>
#include "ipc_jobqueue.h"


/* 
 * Introduction
 * 
 * This header file defines a sem_jobqueue type and its interface":
 *      sem_jobqueue_new(proc_t* proc);
 *      sem_jobqueue_capacity(sem_jobqueue_t* sjq);
 *      sem_jobqueue_dequeue(sem_jobqueue_t* sjq, job_t* dst);
 *      sem_jobqueue_enqueue(sem_jobqueue_t* sjq, job_t* job);
 *      sem_jobqueue_is_empty(sem_jobqueue_t* sjq);
 *      sem_jobqueue_is_full(sem_jobqueue_t* sjq);
 *      sem_jobqueue_peekhead(sem_jobqueue_t* sjq, job_t* dst);
 *      sem_jobqueue_peektail(sem_jobqueue_t* sjq, job_t* dst);
 *      sem_jobqueue_delete(sem_jobqueue_t* sjq);
 *
 * The above functions are direct counterparts to ipc_jobqueue functions (see
 * ipc_jobqueue.h). 
 * This is because, except for sem_jobqueue_new and sem_jobqueue_delete, each
 * sem_jobqueue function is a wrapper for the corresponding ipc_jobqueue
 * function, with appropriate semaphore operations for maintenance
 * of  integrity. That is, to perform queue operations, sem_jobqueue_capacity
 * calls ipc_jobqueue_capacity and sem_jobqueue_dequeue calls 
 * ipc_jobqueue_dequeue and so on.
 *
 * The main difference between an ipc_jobqueue and a sem_jobqueue is that
 * the sem_jobqueue functions use appropriate semaphore operations before
 * and after calling the corresponding ipc_jobqueue function to maintain the 
 * integrity of the underlying shared queue. Otherwise, the usage of an
 * ipc_jobqueue (and an underlying jobqueue) and a sem_jobqueue are almost
 * identical
 *
 * IMPORTANT:
 * Only operate on a sem_jobqueue using the functions defined in 
 * this file. Using a sem_jobqueue in any other way can result in undefined 
 * and erroneous behaviour.
 *
 * See ipc_jobqueue.h for details of ipc_jobqueue operations and documentation
 * See jobqueue.h for details of jobqueue operations.
 */

/* 
 * Definition of struct sem_jobqueue. The struct associates a ipc_jobqueue
 * with semaphores to protect the integrity of the queue when shared by 
 * multiple processes
 *
 * Type alias:
 * A struct sem_jobqueue can also be referred to as sem_jobqueue_t
 *
 * Fields:
 * mutex - a binary mutex semaphore that acts as a lock (is acquired or not) 
 *          and is initialised to available (1) and can be used to provide
 *          mutual exclusion to shared data.
 * full - a counting semaphore that is initialised to unavailable (0), which
 *          means there are no entries in the queue. A process that calls 
 *          dequeue will wait on the full semaphore.
 * empty - a counting semaphore that is initialised to the capacity of the 
 *          queue, which means all slots are available.  A process that
 *          calls enqueue will wait on the empty semaphore.
 * ijq - the ipc_jobqueue that encapsulates a jobqueue in shared memory
 */
typedef struct sem_jobqueue {
    sem_t* mutex;//guard the buff
    sem_t* full;//if its 0, nothing to consume
    sem_t* empty;//number of empty stots to put itm into a buff
    ipc_jobqueue_t* ijq;
} sem_jobqueue_t;

/*
 * sem_jobqueue_new(proc_t* proc)
 * 
 * Creates a new sem_jobqueue and allocates semaphores and other resources 
 * for the queue.
 *
 * Parameters:
 * proc - the non-null descriptor of a process sharing this queue
 *
 * Return:
 * On success: a well-formed sem_jobqueue object that encapsulates the 
 *      queue and associated semaphores
 * On failure: NULL, and errno is set as specified in Errors.
 *
 * Errors:
 * If the call fails, the NULL pointer will be returned and errno will be 
 * set as follows:
 *      EINVAL - invalid argument if proc is NULL
 *      Other values as specified by the system library functions used to
 *      implement the function (see ipc_new in ipc.h and sem_open)
 *
 * See also:
 * proc.h - for a description of the proc type
 * ipc.h - for the ipc type for which the mutex is an alias
 * manual pages for sem_open to create semaphores, and for sem_wait, sem_post 
 *      and sem_delete for possible errors
 */
sem_jobqueue_t* sem_jobqueue_new(proc_t* proc);

/*
 * sem_jobqueue_capacity(sem_jobqueue_t* sjq)
 *
 * This is a wrapper for ipc_jobqueue_capacity.
 *
 * In particular, if the sjq parameter is NULL this function has the 
 * same behaviour as the corresponding ipc_jobqueue function.
 *
 * This function does not change the state of the queue and does not access
 * data that changes after queue initialisation.
 *
 * See the specification of ipc_jobqueue_capacity in ipc_jobqueue.h.
 */
size_t sem_jobqueue_capacity(sem_jobqueue_t* sjq);

/*
 * sem_jobqueue_dequeue(sem_jobqueue_t* sjq, job_t* dst)
 *
 * This is a wrapper for ipc_jobqueue_dequeue.
 *
 * The behaviour of this function is the same as the corresponding ipc_jobqueue
 * function with the following differences due to the use of semaphores to 
 * protect the queue:
 *  - If the queue is empty, the calling process will block until
 *      another process enqueues a job. This means that it is unnecessary to
 *      check whether the queue is empty before calling this function.
 *  - If a sem_wait call on a semaphore protecting the queue fails, this
 *      function will return without dequeueing a job and the state of the 
 *      queue does not change.
 *  - If the sjq parameter is NULL, this function returns NULL and no 
 *      semaphore or other operation is invoked.
 *
 * Return:
 * On success, a pointer to a copy of the job that was at the head of the queue,
 *      and the state of the queue is changed, or NULL if the queue is empty
 * On failure of a sem_wait call or NULL sjq parameter, the NULL pointer and  
 *      the state of the queue is not changed. That is, NULL is returned if 
 *      this function fails.
 *
 * Errors:
 * See errors specified in ipc_jobqueue.h and jobqueue.h.
 * Errors resulting from system calls sem_wait and sem_post are possible..
 *
 * See also:
 * ipc_jobqueue.h and jobqueue.h
 * man pages for sem_wait and sem_post
 */
job_t* sem_jobqueue_dequeue(sem_jobqueue_t* sjq, job_t* dst);

/*
 * sem_jobqueue_enqueue(sem_jobqueue_t* sjq, job-t job)
 *
 * This is a wrapper for ipc_jobqueue_enqueue.
 *
 * The behaviour of this function is the same as the corresponding ipc_jobqueue
 * function with the following differences due to the use of semaphores to 
 * protect the queue:
 *  - If the queue is full, the calling process will block until
 *      another process dequeues a job. This means that it is unnecessary to
 *      check whether the queue is full before calling this function.
 *  - If a sem_wait call on a semaphore protecting the queue fails, this
 *      function will return without enqueueing a job and the state of the 
 *      queue will not be changed.
 *  - If the sjq parameter is NULL, this function returns and no semaphore
 *      or other operation is invoked.
 *
 * Errors:
 * See errors specified in ipc_jobqueue.h and jobqueue.h
 * Errors resulting from system calls sem_wait and sem_post are possible..
 *
 * See also:
 * ipc_jobqueue.h and jobqueue.h
 * man pages for sem_wait and sem_post
 */
void sem_jobqueue_enqueue(sem_jobqueue_t* sjq, job_t* job);

/*
 * sem_jobqueue_is_empty(sem_jobqueue_t* sjq)
 *
 * This is a wrapper for ipc_jobqueue_is_empty.
 *
 * The behaviour of this function is the same as the corresponding ipc_jobqueue
 * function with the following differences due to the use of semaphores to 
 * protect the queue:
 *  - If another process has acquired the mutex protecting the queue, 
 *      the calling process will block until the mutex is available.
 *  - If a sem_wait call on a semaphore protecting the queue fails, this
 *      function will return true regardless of the state of the queue.
 *  - If the sjq parameter is NULL, this function returns true and no semaphore
 *      or other operation is invoked.
 *
 * This function does not change the state of the queue.
 *
 * Return:
 * On success, true if the queue is empty and false otherwise.
 * On failure of a sem_wait call or NULL sjq parameter, true. That is, a queue
 *      is considered empty if this function fails.
 *
 * Errors:
 * See errors specified in ipc_jobqueue.h and jobqueue.h
 * Errors resulting from system calls sem_wait and sem_post are possible..
 *
 * See also:
 * ipc_jobqueue.h and jobqueue.h
 * man pages for sem_wait and sem_post
 */
bool sem_jobqueue_is_empty(sem_jobqueue_t* sjq);

/*
 * sem_jobqueue_is_full(sem_jobqueue_t* sjq)
 *
 * This is a wrapper for ipc_jobqueue_is_full.
 *
 * The behaviour of this function is the same as the corresponding ipc_jobqueue
 * function with the following differences due to the use of semaphores to 
 * protect the queue:
 *  - If another process has acquired the mutex protecting the queue, 
 *      the calling process will block until the mutex is available.
 *  - If a sem_wait call on a semaphore protecting the queue fails, this
 *      function will return true regardless of the state of the queue.
 *  - If the sjq parameter is NULL, this function returns true and no semaphore
 *      or other operation is invoked.
 *
 * This function does not change the state of the queue.
 *
 * Return:
 * On success, true if the queue is full and false otherwise.
 * On failure of a sem_wait call or NULL sjq parameter, true. That is, a queue
 *      is considered full if this function fails).
 *
 * Errors:
 * See errors specified in ipc_jobqueue.h and jobqueue.h
 * Errors resulting from system calls sem_wait and sem_post are possible..
 *
 * See also:
 * ipc_jobqueue.h and jobqueue.h
 * man pages for sem_wait and sem_post
 */
bool sem_jobqueue_is_full(sem_jobqueue_t* sjq);

/*
 * sem_jobqueue_peekhead(sem_jobqueue_t* sjq)
 *
 * This is a wrapper for ipc_jobqueue_peekhead.
 *
 * The behaviour of this function is the same as the corresponding ipc_jobqueue
 * function with the following differences due to the use of semaphores to 
 * protect the queue:
 *  - If another process has acquired the mutex protecting the queue, 
 *      the calling process will block until the mutex is available.
 *  - If a sem_wait call on a semaphore protecting the queue fails, this
 *      function will return NULL regardless of the state of the queue.
 *  - If the sjq parameter is NULL, this function returns NULL and no semaphore
 *      or other operation is invoked.
 *
 * This function does not change the state of the queue.
 *
 * Return:
 * On success, a pointer to a copy of the job at the head of the queue or NULL
 *      if the queue is empty.
 * On failure of a sem_wait call or NULL sjq parameter, the NULL pointer. 
 *      That is, NULL is returned if this function fails.
 *
 * Errors:
 * See errors specified in ipc_jobqueue.h and jobqueue.h
 * Errors resulting from system calls sem_wait and sem_post are possible.
 *
 * See also:
 * ipc_jobqueue.h and jobqueue.h
 * man pages for sem_wait and sem_post
 */
job_t* sem_jobqueue_peekhead(sem_jobqueue_t* sjq, job_t* dst);

/*
 * sem_jobqueue_peektail(sem_jobqueue_t* sjq)
 *
 * This is a wrapper for ipc_jobqueue_peektail.
 *
 * The behaviour of this function is the same as the corresponding ipc_jobqueue
 * function with the following differences due to the use of semaphores to 
 * protect the queue:
 *  - If another process has acquired the mutex protecting the queue, 
 *      the calling process will block until the mutex is available.
 *  - If a sem_wait call on a semaphore protecting the queue fails, this
 *      function will return NULL regardless of the state of the queue.
 *  - If the sjq parameter is NULL, this function returns NULL and no semaphore
 *      or other operation is invoked.
 *
 * This function does not change the state of the queue.
 *
 * Return:
 * On success, a pointer to a copy of the job at the tail of the queue or NULL
 *      if the queue is empty.
 * On failure of a sem_wait call or NULL sjq parameter, the NULL pointer. 
 *      That is, NULL is returned if this function fails.
 *
 * Errors:
 * See errors specified in ipc_jobqueue.h and jobqueue.h
 * Errors resulting from system calls sem_wait and sem_post are possible.
 *
 * See also:
 * ipc_jobqueue.h and jobqueue.h
 * man pages for sem_wait and sem_post
 */
job_t* sem_jobqueue_peektail(sem_jobqueue_t* sjq, job_t* dst);

/*
 * sem_jobqueue_delete(sem_jobqueue_t* sjq)
 * 
 * Deletes a sem_jobqueue, deallocating resources associated with the
 * queue, including closing semaphores.
 * 
 * Parameters:
 * sjq - a non-null pointer to the sem_jobqueue to delete
 *
 * Return:
 * There is no return value for the function. If sjq is not NULL and the call 
 * succeeds, resources associated with the the queue have been freed. If sjq is 
 * NULL this function has no effect.
 *
 * Errors:
 * Various errors with access to any underlying shared memory object may occur
 * in which case the process is likely to terminate with a memory error.
 */
void sem_jobqueue_delete(sem_jobqueue_t* sjq);

#endif
