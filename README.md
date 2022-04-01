
## Completed CSC2035 Assignment - systems programming and inter-process communication (IPC) 
![Badge tracking last commit](https://img.shields.io/github/last-commit/Preffet/C-inter-process-communication-simulation?color=%23a877ed)

### Introduction

For this assignment I was provided with a partially completed project to demonstrate different approaches to maintaining the integrity of an inter-process communication (IPC) application (busy waiting and semaphore approaches). 
My task was to complete the project by implementing supporting library functions. It helped me to reinforce, in practice, the operating systems theory I learnt as part of the CSC2035 module.



### The application/simulation

As shown in the following figure, the project simulates an application in which a set of one or more producer processes creates jobs to submit (enqueue) to a FIFO (first-in, first-out) job queue for one or more consumer processes to dequeue and process. The job queue is in shared memory. In addition each process (producer or consumer) has a private persistent log of jobs that they have produced (if they are a producer) or consumed (if they are a consumer). Many common client/server applications follow this model of one or more producers (clients) submitting work to be done by a one or more consumers (servers).

![Diagram illustrating the application/simulation ](https://github.com/Preffet/markdown-previewer/blob/master/applicationDiagram.jpg)


### The overall application proceeds as follows :
- While a producer process has jobs to be done, they produce a job, enqueue the job on the job queue and log the job in their private log. Enqueuing a job blocks if the queue is full. If there are multiple producers, they are not able to overwrite each other's jobs despite sharing the same queue.
- While there are jobs to consume, a consumer process dequeues the next job from the queue, logs the job in their private log and processes the job. Dequeueing a job blocks if the queue is empty. If there are multiple consumers, each job is only consumed by one consumer despite sharing the queue with the other consumers.

### A job is represented by the following attributes:
- the process id (pid) of the producer of the job
- a job id generated by the producer of the job that is locally unique to that producer
- a job label - an application-specific string that, for example, may describe the job

The combination of job pid and id means that, assuming integrity constraints are maintained, each job will be globally unique even when multiple producers are producing jobs. The job id that is locally unique for a given producer is made globally unique for all producers by qualifying the job id with the producer's globally unique pid. In a real-world version of the application, the combination of pid and job id could be replaced by a could be replaced by an absolute URL that is qualified by the producer's domain name. The label could be replaced by a URL link to a job specification. The overall integrity constraint is that producers should not produce duplicate jobs and each job should only be consumed once by one consumer. That is, no two consumers should consume the same job.

### What I had to do:
- In job.c - add the representation of a job (pid, id and label) and functions to create, set and copy jobs
- In joblog.c - create functions to set up a log and log jobs to file
- In jobqueue.c - add the definition of and functions to manipulate a queue of jobs based on a fixed-sized circular buffer/array
- In shobject_name.c - create the implementation of a utility function to generate shared object names (which are strings of a specified format)
- In ipc_jobqueue.c - add wrapper functions for a queue of jobs that is stored in shared memory for IPC
- In mutex_peterson.c - add the implementation of functions for Peterson's busy-waiting solution to mutual exclusion for two processes
- In sem_jobqueue.c - create wrapper functions for a queue of jobs that is stored in shared memory and uses semaphores to maintain integrity constraints

-----------------------------------------------------------------------------
### How to build the project and run tests

To BUILD THE PROJECT (including tests), in the project directory type the 
following at the terminal command line prompt:
```
    make
```
This will build all project binaries.

If you get unexpected errors, try:
```
    make clean
    make
```

To RUN ALL TESTS, in the directory type the following at the terminal command
line prompt:
```
    ./runtests.sh 
```
To run individual tests type:
```
    ./bin/test/test_<module_name>
```
where <module_name> is replaced by the module you want to test. For example:
```
    ./bin/test/test_joblog
```
to run joblog tests.

The 3rd party munit library (https://nemequ.github.io/munit/#running-tests) has
been used to write tests. You can pass munit command line options to 
runtests.sh or to individual test programs. E.g.:
```
    ./runtests.sh --help
```   
will give a munit help message, as will:
```
    ./bin/test/test_joblog --help
 ```   
The most useful munit command line argument is --log-visible that can make
munit logging visible. munit logging means the logging to stdout or stderr of 
test debug and information messages (not logging of jobs, but see below).

The following invocation of runtests.sh
```
    ./runtests.sh --log-visible debug --show-stderr
```
will log to the terminal window (or stderr) any debug and info level messages 
that have been included in test programs and that you may find useful.

