objects/mutex_noop.o: mutex_noop.c mutex_noop.h mutex.h ipc.h proc.h sim_config.h | objects
	$(CC) -c $(CFLAGS) $< -o $@
