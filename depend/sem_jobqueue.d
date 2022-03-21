objects/sem_jobqueue.o: sem_jobqueue.c shobject_name.h sem_jobqueue.h \
  ipc_jobqueue.h jobqueue.h sim_config.h job.h ipc.h proc.h | objects
	$(CC) -c $(CFLAGS) $< -o $@
