GCC = gcc 
FLAGS = -pedantic -Wall
CFLAGS = -lm -pthread

PROGS: MM1c MM1f MMPosix

MM1c:
	$(GCC) $(FLAGS) module.c -c
	$(GCC) $(FLAGS) $@.c -c 
	$(GCC) $(FLAGS) module.o $@.o -o $@
	
MM1f:
	$(GCC) $(FLAGS) module.c -c
	$(GCC) $(FLAGS) $@.c -c 
	$(GCC) $(FLAGS) module.o $@.o -o $@
		
MMPosix:
	$(GCC) $(FLAGS) module.c -c
	$(GCC) $(FLAGS) $@.c -c 
	$(GCC) $(FLAGS) module.o $@.o -o $@

clean:
	$(RM) $(PROGS) *.o
	$(RM) MM1c MM1f MMPosix
