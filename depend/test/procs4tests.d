objects/test/procs4tests.o: test/procs4tests.c test/procs4tests.h test/../proc.h \
  test/../sim_config.h | objects/test
	$(CC) -c $(CFLAGS) $< -o $@
