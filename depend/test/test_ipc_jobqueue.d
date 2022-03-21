objects/test/test_ipc_jobqueue.o: test/test_ipc_jobqueue.c test/test_jobqueue_common.h \
  test/munit/munit.h test/../sim_config.h test/../job.h \
  test/../jobqueue.h test/test_ipc_jobqueue.h test/../ipc_jobqueue.h \
  test/../ipc.h test/../proc.h test/procs4tests.h | objects/test
	$(CC) -c $(CFLAGS) $< -o $@
