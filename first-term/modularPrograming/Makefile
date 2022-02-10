GCC= gcc
FLAGS =-ansi -pedantic -Wall

PROGS = main

main:
	$(GCC) $(FLAGS) functions.c -c
	$(GCC) $(FLAGS) $@.c -c
	$(GCC) $(FLAGS) -o ejecutable functions.o $@.o
clean:
	$(RM) $(PROGS) *.o