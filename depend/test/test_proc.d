objects/test/test_proc.o: test/test_proc.c test/test_proc.h test/munit/munit.h \
  test/../proc.h test/../sim_config.h | objects/test
	$(CC) -c $(CFLAGS) $< -o $@
