# Parallel and modular folder. 

In this folder you will find these files:

* *MM1c.c* that is an implementation of matrix multiplication by columns. Let **A** and **B** two matrixes and you want to find the multiplication between them. This multiplication is done in two pointers that represent these matrixes in a row. The multiplication is classical (rows x columns)
* *MM1f.c* that is an implementation of matrix multiplication by rows. Let **A** and **B** two matrixes and you want to find the multiplication between them. This multiplication is done in two pointers that represent these matrixes in a row. The multiplication is classical (rows x columns) but the matrix b is trasposed and you will multiply them as row x row to get the multiplication
* *MMPosix.c* That is an implementation of matrix multiplication using threads.
* *module.c* That is the file with all function implementations defined in *module.h* and are used in the above files.
* *module.h* That is the file with all function definitions that are used and imported in the above files.
* *Makefile* that is a script to compile all the programs: *MMPosix*, *MM1f* and *MM1c*. This will generate executables to run the programs.


To compile all use this command

```
make PROGS
```

And this will generate all the executables

