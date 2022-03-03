GCC=gcc 
FLAGS=-std=c99 -pthread
PROGS=Posix01

Posix01:
	$(GCC) $(FLAGS) module.c -c
	$(GCC) $(FLAGS) $@.c -c
	$(GCC) $(FLAGS) module.o $@.o -o $@
clean:
	$(RM) $(PROGS) *.o