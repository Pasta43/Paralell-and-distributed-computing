GCC = gcc-11
FLAGS = -ansi -pedantic -Wall 
CFLAGS = -lm -lpthread -fopenmp 
THEPROGS=MM1c MM1f MMPosix MM1cOMP

PROGS: MM1c MM1f MMPosix MM1cOMP

MM1c:
	$(GCC) $(FLAGS) module.c -c -D_POSIX_C_SOURCE=199309L 
	$(GCC) $(FLAGS) $@.c -c 
	$(GCC) $(FLAGS) module.o $@.o -o $@

MM1cOMP:
	$(GCC) $(FLAGS) module.c -c -D_POSIX_C_SOURCE=199309L $(CFLAGS)
	$(GCC) $(FLAGS) $@.c -c $(CFLAGS)
	$(GCC) $(FLAGS) module.o $@.o -o $@ $(CFLAGS)

MM1f:
	$(GCC) $(FLAGS) module.c -c -D_POSIX_C_SOURCE=199309L 
	$(GCC) $(FLAGS) $@.c -c 
	$(GCC) $(FLAGS) module.o $@.o -o $@
		
MMPosix:
	$(GCC) $(FLAGS) module.c -c $(CFLAGS) -D_POSIX_C_SOURCE=199309L 
	$(GCC) $(FLAGS) $@.c -c $(CFLAGS) 
	$(GCC) $(FLAGS) module.o $@.o -o $@ $(CFLAGS) 

clean:
	$(RM) $(THEPROGS) *.o