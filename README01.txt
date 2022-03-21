README for release 01 of CSC2035 assignment 1 code base

The initial project directory contains:
    - the project source code (.c and .h files) for release 01.
        The header (.h) files provide documentation.
    - make files to build the project
    - README01.txt: this file
    - README_joblog_example.txt: an example job log file
    - README_test_r01_init.txt: expected test output for the initial 01 
        release of the project
    - README_test_r01_pass.txt: expected test output when all functions 
        pass tests for release 01
    - runtests.sh: a shell script to run tests that have been compiled in 
        bin/test (see below)
    - test directory containing unit test source code
        e.g. tests of joblog.c are in test/test_joblog.h and 
        test/test_joblog.c
    - depend directory of build dependencies (including test dependencies in 
        depend/test) created by make depend

The following directories are created when the project is built or during tests:
    - objects directory for compiled object files created when the project 
        is built, created by make
    - bin directory for compiled application (in bin) and test binaries 
        (in bin/test), created by make
    - out directory for job logs, created by bin/test/test_joblog and 
        applications
    
Your task with the release 01 code is to implement the following functions:

    In job.c:
        job_copy, job_init, job_is_equal, job_set, job_delete
    as specified in job.h and the assignment specification (job_new is 
    provided for you)
        
    In joblog.c : 
        joblog_read_entry, joblog_write_entry, joblog_delete
    as specified in joblog.h and the assignment specification (new_log_name
    and joblog_init are provided for you)

    In jobqueue.c : 
        jobqueue_new, jobqueue_capacity, jobqueue_dequeue, jobqueue_is_full,
        jobqueue_peektail, jobqueue_delete
    as specified in jobqueue.h and the assignment specification (jobqueue_init,
    jobqueue_enqueue, jobqueue_is_empt and jobqueue_peekhead are provided for 
    you))

    In shobject_name.c : 
        shobject_name
    as specified in shobject_name.h and the assignment specification

Each of the above functions has a dummy implementation to enable compilation.
These implementations should be replaced. Do NOT change the function
signatures. Other functions in the above files may be implemented for you.
Looking at those other functions will help with the implementation of the 
above functions. Looking at the relevant test code (e.g. test/test_job.c for 
job.c) will help with the implementation of the above functions. 

Hints for the implementation of a function are also sometimes provided in 
comments in the relevant .c file. 

If you think it will help to reduce code duplication or simplify logic, you may
define your own helper functions in the above files. In which case,
they should be declared static to ensure they are private to the given 
compilation unit.

You can, and should, look at other files but do NOT edit, or delete,
other files and do NOT edit functions other than those listed above. And 
do NOT change function signatures. 

First, build the project and run the project tests, as in the following
instructions.

Note, building the project may give compilation errors. It is your job to fix
them if they are caused by code in files you have edited. If they are caused by 
code in other files, then report them using the programming support form
accessed from Canvas.

-----------------------------------------------------------------------------

To BUILD THE PROJECT (including tests), in the project directory type the 
following at the terminal command line prompt:

    make

This will build all project binaries.

If you get unexpected errors, try:

    make clean
    make

instead.

To RUN ALL TESTS, in the directory type the following at the terminal command
line prompt:

    ./runtests.sh 

To run individual tests type:

    ./bin/test/test_<module_name>

where <module_name> is replaced by the module you want to test. For example:

    ./bin/test/test_joblog

to run joblog tests.

The 3rd party munit library (https://nemequ.github.io/munit/#running-tests) has
been used to write tests. You can pass munit command line options to 
runtests.sh or to individual test programs. E.g.:

    ./runtests.sh --help
    
will give a munit help message, as will:

    ./bin/test/test_joblog --help
    
The most useful munit command line argument is --log-visible that can make
munit logging visible. munit logging means the logging to stdout or stderr of 
test debug and information messages (not logging of jobs, but see below).

The following invocation of runtests.sh

    ./runtests.sh --log-visible debug --show-stderr

will log to the terminal window (or stderr) any debug and info level messages 
that have been included in test programs and that you may find useful.

PRESERVING JOBLOG OUTPUT

The --log-visible option also has the effect of preserving joblog files in 
the out directory. In a normal run of joblog tests, the log files are 
removed after each test. If the --log-visible option is selected, then the 
output is not removed and you can look at the content of files created in 
the out directory. This has the side effect of not running the joblog_delete 
test.

-----------------------------------------------------------------------------

SUMMARY

When you first download and extract the project, cd to the project directory 
and type the following at the terminal command line prompt:

    make
    ./runtests.sh
    
this will build the project and run all tests.

The output of runtests.sh for the intitial project distribution should be 
similar to that shown in README_test_r01_init.txt. 

Once you are working normally on the project you can just do:

    make 
    ./runtests.sh
    
when you want to re-build the project and run tests.

Or:

    make clean
    make
    ./runtests.sh
    
if making without cleaning temporary directories and binaries seems to 
cause unexpected errors.

Remember, "make" may give compilation errors. It is your job to fix them
if they are caused by code in files you have edited. If they are caused by 
code in other files, then report them using the programming support form
accessed from Canvas.

-----------------------------------------------------------------------------


