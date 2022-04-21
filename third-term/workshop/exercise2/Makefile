GCC = gcc-11
FLAGS =-pedantic -Wall 
THEPROGS=main

PROGS: main 

main:
	$(GCC) $(FLAGS) cfib.c -c 
	$(GCC) $(FLAGS) $@.c -c 
	$(GCC) $(FLAGS) cfib.o $@.o -o cfib.x
	python setup.py build_ext --inplace

clean:
	$(RM) $(THEPROGS) *.o
	$(RM) cyfib.cpython-38-x86_64-linux-gnu.so
	$(RM) -r build/
	$(RM) -r __pycache__/
	$(RM) cfib.x
