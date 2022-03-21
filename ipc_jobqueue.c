/*
 * Replace the following string of 0s with your student number
 * c0037826
 */
#include "ipc_jobqueue.h"

/* 
 * DO NOT EDIT the ipc_jobqueue_new function.
 */
ipc_jobqueue_t* ipc_jobqueue_new(proc_t* proc) {
    ipc_jobqueue_t* ijq = ipc_new(proc, "ipc_jobq", sizeof(jobqueue_t));
    
    if (!ijq) 
        return NULL;
    
    if (proc->is_init)
        jobqueue_init((jobqueue_t*) ijq->addr);
    
    return ijq;
}

/* 
 * TODO: you must implement this function.
 * Hint:
 * - look at how the shared jobqueue_t is accessed in ipc_jobqueue_new and 
 *      passed to jobqueue_init (ipc_jobqueue_new initialises the shared 
 *      jobqueue by passing it to a function defined in jobqueue.h)
 */
size_t ipc_jobqueue_capacity(ipc_jobqueue_t* ijq) {
    if(ijq)
    {
        return jobqueue_capacity((jobqueue_t*) ijq->addr);
    }
    else{
        return 0;
    }
}

/* 
 * TODO: you must implement this function.
 * Hints:
 * - this is a wrapper for jobqueue function jobqueue_dequeue
 * - and remember you must call do_critical_work after dequeuing the job
 */
job_t* ipc_jobqueue_dequeue(ipc_jobqueue_t* ijq, job_t* dst) {
    if(!ijq)
    {
        return NULL;
    }
    else{
        job_t* newDst = jobqueue_dequeue((jobqueue_t*) ijq->addr,dst);
        do_critical_work(ijq->proc);
        return newDst;
    }
}

/* 
 * TODO: you must implement this function.
 * Hint:
 * - see ipc_jobqueue_dequeue hint
 */
void ipc_jobqueue_enqueue(ipc_jobqueue_t* ijq, job_t* job) {
    if(!ijq)
    {
        return;
    }
    else{
        do_critical_work(ijq->proc);
        jobqueue_enqueue((jobqueue_t*) ijq->addr,job);
        return;
    }
}
    
/* 
 * TODO: you must implement this function.
 * Hint:
 * - see ipc_jobqueue_dequeue hint
 */
bool ipc_jobqueue_is_empty(ipc_jobqueue_t* ijq) {
    if(!ijq){return true;}
    
    else{
        bool empty = true;
        do_critical_work(ijq->proc);
        empty = jobqueue_is_empty((jobqueue_t*) ijq->addr);
        return empty;
    }
}

/* 
 * TODO: you must implement this function.
 * Hint:
 * - see ipc_jobqueue_dequeue hint
 */
bool ipc_jobqueue_is_full(ipc_jobqueue_t* ijq) {
    if(!ijq){return true;}
    
    else{
        bool full = true;
        do_critical_work(ijq->proc);
        full = jobqueue_is_full((jobqueue_t*) ijq->addr);
        return full;
    }
}

/* 
 * TODO: you must implement this function.
 * Hint:
 * - see ipc_jobqueue_dequeue hint
 */
job_t* ipc_jobqueue_peekhead(ipc_jobqueue_t* ijq, job_t* dst) {
    if(!ijq){return NULL;}
    
    else{
        do_critical_work(ijq->proc);
        job_t* job_at_head = jobqueue_peekhead((jobqueue_t*) ijq->addr, dst);
        return job_at_head;
    }
}
    
/* 
 * TODO: you must implement this function.
 * Hint:
 * - see ipc_jobqueue_dequeue hint
 */
job_t* ipc_jobqueue_peektail(ipc_jobqueue_t* ijq, job_t* dst) {
    if(!ijq){return NULL;}
    
    else{
        do_critical_work(ijq->proc);
        job_t* job_at_tail = jobqueue_peektail((jobqueue_t*) ijq->addr, dst);
        return job_at_tail;
    }
}

/* 
 * TODO: you must implement this function.
 * Hint:
 * - look at how the ipc_jobqueue is allocated in ipc_jobqueue_new
 */
void ipc_jobqueue_delete(ipc_jobqueue_t* ijq) {
    if(!ijq){return;}
    
    else{
        free(ijq);
        return;
    }
}
