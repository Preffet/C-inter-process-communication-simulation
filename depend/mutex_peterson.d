objects/mutex_peterson.o: mutex_peterson.c mutex_peterson.h mutex.h ipc.h proc.h \
  sim_config.h | objects
	$(CC) -c $(CFLAGS) $< -o $@
