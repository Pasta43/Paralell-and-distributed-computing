#Plegadora paralela y modular.

En esta carpeta encontrará estos archivos:

* *MM1c.c* que es una implementación de la multiplicación de matrices por columnas. Sean **A** y **B** dos matrices y desea encontrar la multiplicación entre ellas. Esta multiplicación se realiza en dos punteros que representan estas matrices en una fila. La multiplicación es clásica (filas x columnas)
* *MM1f.c* que es una implementación de la multiplicación de matrices por filas. Sean **A** y **B** dos matrices y desea encontrar la multiplicación entre ellas. Esta multiplicación se realiza en dos punteros que representan estas matrices en una fila. La multiplicación es clásica (filas x columnas) pero la matriz b está traspuesta y las multiplicarás como fila x fila para obtener la multiplicación
* *MMPosix.c* Esa es una implementación de la multiplicación de matrices usando hilos.
* *module.c* Ese es el archivo con todas las implementaciones de funciones definidas en *module.h* y se utilizan en los archivos anteriores.
* *module.h* Ese es el archivo con todas las definiciones de funciones que se usan e importan en los archivos anteriores.
* *Makefile* que es un script para compilar todos los programas: *MMPosix*, *MM1f* y *MM1c*. Esto generará ejecutables para ejecutar los programas.

