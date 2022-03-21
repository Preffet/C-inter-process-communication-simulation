objects/jobqueue.o: jobqueue.c jobqueue.h sim_config.h job.h | objects
	$(CC) -c $(CFLAGS) $< -o $@
