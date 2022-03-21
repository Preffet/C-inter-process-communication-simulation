objects/ipc_jobqueue.o: ipc_jobqueue.c ipc_jobqueue.h jobqueue.h sim_config.h \
  job.h ipc.h proc.h | objects
	$(CC) -c $(CFLAGS) $< -o $@
