objects/proc.o: proc.c proc.h sim_config.h | objects
	$(CC) -c $(CFLAGS) $< -o $@
