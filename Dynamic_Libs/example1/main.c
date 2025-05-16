#include "mylib.h"

int main() {
    printf("%d\n", add(5,3));
    printf("%d\n", minus(5,3));
    printf("%d\n", multiply(5,3));
    printf("%d\n", divide(5,3));

    return 0;
}

/*
# Compile library
gcc -c mylib.c -o mylib.o
ar rcs libmylib.a mylib.o

# Compile main program and link statically
gcc main.c -L. -lmylib -o main

export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH

# Run
./main
*/