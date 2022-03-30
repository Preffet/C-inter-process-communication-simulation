
## Completed CSC2035 Assignment - systems programming and inter-process communication (IPC) 

Introduction

For this assignment I was provided with a partially completed project to demonstrate different approaches to maintaining the integrity of an inter-process communication (IPC) application (busy waiting and semaphore approaches). 
My task was to complete the project by implementing supporting library functions. It helped me to reinforce, in practice, the operating systems theory I learnt as part of the CSC2035 module.



### The application/simulation

As shown in the following figure, the project simulates an application in which a set of one or more producer processes creates jobs to submit (enqueue) to a FIFO (first-in, first-out) job queue for one or more consumer processes to dequeue and process. The job queue is in shared memory. In addition each process (producer or consumer) has a private persistent log of jobs that they have produced (if they are a producer) or consumed (if they are a consumer). Many common client/server applications follow this model of one or more producers (clients) submitting work to be done by a one or more consumers (servers).

![Diagram illustrating the application/simulation ](https://github.com/Preffet/markdown-previewer/blob/master/applicationDiagram.jpg)
