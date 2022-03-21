objects/shobject_name.o: shobject_name.c sim_config.h shobject_name.h | objects
	$(CC) -c $(CFLAGS) $< -o $@
