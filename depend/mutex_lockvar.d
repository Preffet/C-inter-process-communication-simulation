objects/mutex_lockvar.o: mutex_lockvar.c mutex_lockvar.h mutex.h ipc.h proc.h \
  sim_config.h | objects
	$(CC) -c $(CFLAGS) $< -o $@
