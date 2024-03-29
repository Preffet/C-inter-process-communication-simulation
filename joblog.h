/******** DO NOT EDIT THIS FILE ********/
#ifndef _JOBLOG_H
#define _JOBLOG_H
#include "job.h"
#include "proc.h"

/*
 * joblog_init(proc_t* proc)
 *
 * Initialise a joblog for the given process to write jobs to.
 * Log initialisation does the following:
 * 1. if proc is the init process (its is_init field is true), create the 
 *    parent directory (./out) for logs if it does not already exist. 
 * 2. delete any existing log for the given process
 *
 * Note joblogs are initialised as part of the set of simulations in 
 * the simulation_setup function in sim_control.c. Or as part of the 
 * joblog tests.
 *
 * Parameters:
 * proc - the non-NULL descriptor of a process that will log jobs
 *
 * Return:
 * On success: 0
 * On failure: -1, and errno is set as specified in Errors.
 *
 * Errors:
 * If the call fails, -1 will be returned and errno will be set as follows:
 *      EINVAL - invalid argument if proc is NULL
 *      Other values as specified by the system library functions used to
 *      implement the function (see below)
 *
 * See also:
 * proc.h - for a description of the proc type
 * man pages for mkdir, unlink and stat
 */
int joblog_init(proc_t* proc);

/*
 * joblog_read_entry(proc_t* proc, int entry_num, char* buf)
 *
 * Read the specified entry from the given process' log. The entry_num 
 * specifies the log entry to read. If there are N entries in the log file, 
 * a valid entry_num will be in range 0 to N - 1. The first (or oldest)
 * entry in the log has entry_num 0. That is the lines of the log file are 
 * indexed by entry_num like an array from 0 to N - 1.
 * If there is an entry for the given entry_num, then either:
 *  - the entry is read into the string buffer "buf", if buf is not NULL, or
 *  - if buf is NULL, the entry is read into a new dynamically allocated string.
 * The entry will be a string of the following form: 
 *      pid:<proc_id>,id:<job_id>,label:<label>
 * Whether buf is NULL or not, the string is returned as the result of calling
 * the function.
 * If buf is NULL, it is the responsibility of the programmer who calls the 
 * the joblog_read_entry function to deallocate the resulting dynamically
 * allocated string.
 * The returned string does not include an end of line character. See
 * joblog_write_entry for more information on the log entry format.
 *
 * Usage:
 *      // One way to read and print each entry from a log in turn is:
 *      int i = 0;
 *      char* entry = NULL;
 *   
 *      while ((entry = joblog_read_entry(proc, i, NULL))) {
 *          printf("%s\n", entry);
 *          free(entry);
 *          i++;
 *      }
 *
 * Parameters:
 * proc - the non-null descriptor of the process whose log to read
 * entry_num - the non-negative number of the entry in the log to read
 * buf - a buffer to read the entry into. If buf is not NULL then its size
 *      must be at least JOBLOG_ENTRY_SIZE bytes. If buf is NULL, a 
 *      buffer of that size is dynamically allocated.
 *
 * Return:
 * On success: a string that is the entry in the given process' log specified 
 *      by the given entry_num. If the string is dynamically allocated (see 
 *      above), it is the responsibility of the user of this function to free
 *      the memory allocated by the function.
 * On failure: NULL, and failures are handled as specified in the Notes 
 *      section
 *
 * Errors:
 * joblog_read_entry() returns NULL for most errors. Errors caused by the 
 * joblog_read_entry function are suppressed as if the function were never
 * called. See the Notes section.
 * joblog_read_entry() does not attempt to read the log and returns NULL and 
 * does NOT set the errno for following errors:
 * 1. proc is NULL
 * 2. entry_num is < 0
 * 3. a filename cannot be generated from the given proc descriptor
 *
 * Notes:
 * If joblog_read_entry() fails, in the following cases there will be no 
 * attempt to read the log, NULL will be returned and errno will set to the 
 * value it had on entry to the function:
 * 1. The proc parameter is NULL
 * 2. entry_num is < 0
 * 3. A file name cannot be generated from the given process descriptor.
 * 4. The log file cannot be opened.
 * 
 * If the above errors do not occur, joblog_read_entry() attempts to read 
 * the entry specified by the given entry_num. 
 * If there is no entry in the log file for the given entry_num (e.g. 
 * entry_num is beyond the end of the file), then NULL will be returned 
 * and errno will have the value it had on entry to the function.
 * Other file processing errors may occur during attempts to read which 
 * are in effect ignored and the errno is set to the value it had on entry
 * to the function or, in some circumstances, an error may cause program
 * termination.
 * In summary, in the event of a detectable error or failure, implementations 
 * of this function will ensure that it is as if the function has no effect 
 * and no side effects and, in particular, will set the errno to the value 
 * it had before the function was called.
 *
 * See also:
 * proc.h - for a description of the proc type
 */
char* joblog_read_entry(proc_t* proc, int entry_num, char* buf);

/*
 * joblog_write_entry(proc_t* proc, job_t* job)
 *
 * Write an entry for the given job to the given process' log. 
 * Each log entry is on a single line in the log text file. The entry is
 * of the following form:
 *      pid:<proc_id>,id:<job_id>,label:<label>
 *
 * where <proc_id> is replaced by the 7 digit id of the process that created
 * the job, <job_id> is replaced by a 5 digit job id and <label> is replaced by 
 * the job's label of length MAX_NAME_SIZE - 1. The numeric ids are padded 
 * with leading 0s if they have less than the specified number of digits. The 
 * label is padded with trailing PAD_CHAR characters (see job.h). 
 * JOBLOG_ENTRY_FMT defines the format of an entry string.
 *
 * For example, for a job with pid of creating process 5 and id 10 and label
 * "newjob", the log entry will be:
 * 
 * pid:0000005,id:00010,label:newjob************************
 *
 * This ensures that each entry in the log file is exactly JOBLOG_ENTRY_SIZE 
 * characters long including the new line.
 *
 * Note: the pid in a log entry is the pid of the process that created the job. 
 * This is not necessarily the same as the calling process that is logging the
 * job in its log file. For example, a consumer process with pid 212 could be 
 * logging a job produced by a producer process with pid 99. In this case, the 
 * pid associated with the job in the log is 99 - the pid of the creator of the 
 * job.
 *
 * Log entries are appended to the log file. That is, the oldest log entry is 
 * at line 1 (entry number 0), the next oldest at line 2 etc.
 *
 * See README_joblog_example.txt for an example joblog file.
 *
 * Usage:
 *      joblog_write_entry(proc, job);
 * 
 * See simulation_update in sim_control.c for how the joblog_write_entry
 * function is used to write log entries.
 *
 * Parameters:
 * proc - the non-null descriptor of a process that will log jobs
 * job - the non-null pointer to a job descriptor
 *
 * Return:
 * joblog_write_entry() does not return any value. See the Notes section.
 *
 * Errors:
 * joblog_write_entry() returns without reporting errors caused by this 
 * function. Therefore, on return from this function the value of errno 
 * should be same as its value on entry to the function. See the Notes section.
 *
 * Notes:
 * If joblog_write_entry() fails, the log entry is not written to the 
 * log file and the file will remain unchanged. Errors caused by the 
 * joblog_write_entry function are suppressed as if the function were never
 * called. The function guarantees the following: 
 * 1. If either proc or job is NULL, the function returns without attempting
 *      to write to the log file.
 * 2. If a file name cannot be generated from the given process descriptor,
 *      the function returns without attempting to write to the log file.
 * 3. If the log file cannot be opened, the function returns without
 *      attempting to write to file.
 * 4. If a write to file is attempted but fails, errors are suppressed, the 
 *      function returns and the value of errno is the same as it was on 
 *      entry to the function. Some errors that cause program termination 
 *      cannot be suppressed.
 * In summary, in the event of a detectable error or failure, implementations 
 * of this function will ensure that it is as if the function has no effect 
 * and no side effects and, in particular, will set the errno to the value 
 * it had before the function was called.
 *
 * See also:
 * job.h - for a description of the job type
 * proc.h - for a description of the proc type
 */
void joblog_write_entry(proc_t* proc, job_t* job);

/*
 * joblog_delete(proc_t* proc)
 *
 * Delete the given process' log.
 *
 * Usage:
 *      joblog_delete(proc);
 *  
 * Parameters:
 * proc - the non-null descriptor of the process whose log to delete
 *
 * Return:
 * joblog_delete() does not return any value.
 *
 * Errors:
 * joblog_delete() returns without reporting errors. Therefore, errno 
 * will have the value it had on entry to the function after this function 
 * returns. 
 *
 * See also:
 * proc.h - for a description of the proc type
 */
void joblog_delete(proc_t* proc);

#endif
