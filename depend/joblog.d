objects/joblog.o: joblog.c joblog.h job.h sim_config.h proc.h | objects
	$(CC) -c $(CFLAGS) $< -o $@
