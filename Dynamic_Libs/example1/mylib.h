#ifndef MYLIB_H
#define MYLIB_H

#include <stdio.h>

int add(int a, int b);
int minus(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

#endif

/*
# Compile to object file (.o)
gcc -c mylib.c -o mylib.o

# Create static library (.a)
ar rcs libmylib.a mylib.o

ar: Archiver utility (creates .a files).

rcs flags:

r (replace existing files),

c (create if it doesn’t exist),

s (write an index).
*/
