objects/job.o: job.c job.h sim_config.h | objects
	$(CC) -c $(CFLAGS) $< -o $@
