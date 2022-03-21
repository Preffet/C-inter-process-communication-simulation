#include "mutex_lockvar.h"

/* mutex.h contains the specification of functions in this file */

mutex_t* mutex_new(proc_t* proc) {
    return ipc_new(proc, "mux_lockvar", sizeof(mutex_lockvar_t));
}

void mutex_enter(mutex_t* mux) {
    if (!mux) return;
        
    mutex_lockvar_t* lock = (mutex_lockvar_t*) mux->addr;

    while (*lock) ;
    
    *lock = 1;    
}

void mutex_leave(mutex_t* mux) {
    if (!mux) return;
        
    mutex_lockvar_t* lock = (mutex_lockvar_t*) mux->addr;

    *lock = 0;
}

void mutex_delete(mutex_t* mux) {
    ipc_delete(mux);
}



