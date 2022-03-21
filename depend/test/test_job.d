objects/test/test_job.o: test/test_job.c test/test_job.h test/munit/munit.h \
  test/../job.h test/../sim_config.h | objects/test
	$(CC) -c $(CFLAGS) $< -o $@
