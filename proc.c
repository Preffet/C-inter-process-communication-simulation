/******** DO NOT EDIT THIS FILE ********/
#include <string.h>
#include <time.h>
#include "proc.h"

proc_t* proc_new(proctype_t type, char* name, pid_t pid, int jobs, bool is_init,   
    int delay_start, int delay_exit, work_ms_t crit_work, 
    work_ms_t noncrit_work) {
    /* the proctype_label array is declared static so that
     * it is not allocated on every call to the function
     */
    static const char* proctype_label[] = { 
        "bwait_cons",
        "bwait_prod", 
        "sem_cons", 
        "sem_prod"
    };

    if (type < BWAIT_CONS_PROC || type > SEM_PROD_PROC)
        return NULL;
     
    if (jobs < 1) 
        return NULL;

    name = name && name[0] ? name : "none"; 
    
    proc_t* proc = (proc_t*) malloc(sizeof(proc_t));
    
    if (proc) {
        proc->type = type;
        strncpy(proc->type_label, proctype_label[type], MAX_NAME_SIZE - 1); 
        proc->type_label[MAX_NAME_SIZE - 1] = '\0';
        strncpy(proc->name, name, MAX_NAME_SIZE - 1);
        proc->name[MAX_NAME_SIZE - 1] = '\0';
        proc->id = pid;
        proc->jobs = jobs;
        proc->is_init = is_init;
        proc->delay_start = delay_start;
        proc->delay_exit = delay_exit;
        proc->crit_work = crit_work;
        proc->noncrit_work = noncrit_work;
    }
        
    return proc;
}

static void delay_randms(long min_ms, long max_ms) {
    if (min_ms < 1 || max_ms <= min_ms)
        return;
        
    long ms = (random() % (max_ms - min_ms + 1)) + min_ms;
    
    delay_ms(ms);
}

void delay_ms(long ms) {
    if (ms < 1)
        return;
        
    struct timespec req;
    
    req.tv_sec = ms / 1000;
    req.tv_nsec = (ms - (req.tv_sec * 1000)) * 1000000L;
    
    nanosleep(&req, NULL);
}

void do_noncritical_work(proc_t* proc) {
    if (!proc) return;
    
    delay_randms(proc->noncrit_work.min, proc->noncrit_work.max); 
}

void do_critical_work(proc_t* proc) {
    if (!proc) return;
    
    delay_randms(proc->crit_work.min, proc->crit_work.max); 
}

void proc_delete(proc_t* proc) {
    free(proc);
}

