objects/ipc.o: ipc.c ipc.h proc.h sim_config.h shobject_name.h | objects
	$(CC) -c $(CFLAGS) $< -o $@
