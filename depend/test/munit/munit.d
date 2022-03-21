objects/test/munit.o: test/munit/munit.c test/munit/munit.h | objects/test
	$(CC) -c $(CFLAGS) $< -o $@
