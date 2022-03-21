Stage 2 of the project contains all of the files specified in README01.txt plus the following files:
    - project source code (.c and .h files) for the IPC parts of the project 
    (including the files you have to edit: ipc_jobqueue.c, mutex_peterson.c
    and sem_jobqueue.c)
    - additional tests files in the test directory for the new source code
    - updated test files for some of the files in the first release of the 
    project
    
-----------------------------------------------------------------------------

UPDATING YOUR CODE BASE

The new release has a complete set of source code and tests. Therefore you 
can work from the directory for the new release.

The simplest way for you to update your code base is to copy files from 
your old working directory for the project to the new directory containing 
all the new files and updates.

The files you need to copy to the new directory are:
    job.c
    joblog.c
    jobqueue.c
    shobject_name.c
    
You should not need to copy any other files from your old working directory 
for the project.

Make a backup before you do any copying to make sure you do not overwrite
any existing work.

-----------------------------------------------------------------------------

WHAT YOU HAVE TO DO NOW

Complete the work for stage 1 of the project and implement the following 
functions:

    In ipc_jobqueue.c : 
        ipc_jobqueue_capacity, ipc_jobqueue_dequeue, ipc_jobqueue_enqueue,    
        ipc_jobqueue_is_empty, ipc_jobqueue_is_full, ipc_jobqueue_peekhead,
        ipc_jobqueue_peektail, ipc_jobqueue_delete
    as specified in ipc_jobqueue.h and the assignment specification.
    Note: ipc_jobqueue is a wrapper for a jobqueue. The queue functionality
    is provided by jobqueue function calls.

    In mutex_peterson.c : 
        mutex_new, mutex_enter, mutex_leave, mutex_delete
    as specified in mutex_peterson.h and the assignment specification

    In sem_jobqueue.c : 
        sem_jobqueue_capacity, sem_jobqueue_dequeue, sem_jobqueue_enqueue,    
        sem_jobqueue_is_empty, sem_jobqueue_is_full, sem_jobqueue_peekhead,
        sem_jobqueue_peektail, sem_jobqueue_delete
    as specified in sem_ipc_jobqueue.h and the assignment specification
    Note: sem_jobqueue is a wrapper for an ipc_jobqueue. The queue 
    functionality is provided by ipc_jobqueue function calls.

Each of the above functions has a dummy implementation to enable compilation.
These implementations should be replaced but do NOT change the function
signatures. Other functions in the above files may be implemented for you.
Looking at those other functions will help with the implementation of the 
above functions. 

If you think it will help to reduce code duplication or simplify logic, 
you may define your own helper functions in the above files. In which case,
they should be declared static to ensure they are private to the given 
compilation unit.

Hints for the implementations are provided in comments to each function. 
Also look at their associated header files. 

You can, and should, look at other files but do NOT edit, or delete,
other files and do NOT edit functions other than those listed above. The 
definition of the ipc_t type (struct ipc) is particularly relevant to this 
stage and the new and delete functions you have to implement.

Build instructions etc. are provided in README01.txt.

There have been some changes to tests for the code in release 01. Therefore, 
you should run tests again for your existing code. The next section summarises
changes to tests.

-----------------------------------------------------------------------------

SUMMARY OF CHANGES TO RELEASE 1 TESTS

The following tests have been updated to provide additional test coverage.

    - test_job: updates include verifying that copies of jobs are equal but 
        not identical (unless dst and src parameters are identical)
    - test_joblog: no additional coverage just a clarifying comment added to: 
        test_joblog_read_entry_null
    - test_jobqueue: updates include verifying tail/head indexes
        after queue operations, and that jobs returned are distinct copies,
        and the addition of test_jobqueue_peektail_wrap to cover correct
        behaviour of peektail for the case when jobs wrap (e.g. when the
        value of the tail index becomes 0 again)

There have also been changes to documentation in header files: job.h, 
joblog.h, jobqueue.h and shobject_name.h, to clarify requirements. The 
requirements have not changed. The changes are intended to make them clearer.

-----------------------------------------------------------------------------

WHAT WILL BE IN THE NEXT CODE RELEASE

There will be a third code release for assignment 1 that will provide the 
IPC simulation applications that use the libraries you are developing.

You do NOT need the third release to complete the assignment or to test
your code. The third release will demonstrate the use of 
busy waiting and semaphore solutions to mutual exclusion and does NOT require
any programming by you.

-----------------------------------------------------------------------------


