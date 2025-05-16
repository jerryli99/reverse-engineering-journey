//main_dynamic.c -- Load .so manually

#include <stdio.h>
#include <dlfcn.h> //required for dynamic loading

int main() {
    void* handle = dlopen("./libmylib.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }

    //Get function pointers
    int (*add)(int, int) = dlsym(handle, "add");
    int (*minus)(int, int) = dlsym(handle, "minus");
    int (*multiply)(int, int) = dlsym(handle, "multiply");
    int (*divide)(int, int) = dlsym(handle, "divide");

    if (!add || !minus || !multiply || !divide) {
        fprintf(stderr, "Error: %s\n", dlerror());
        dlclose(handle);
        return 1;
    }

    printf("%d\n", add(5,3));
    printf("%d\n", minus(5,3));
    printf("%d\n", multiply(5,3));
    printf("%d\n", divide(5,3));

    dlclose(handle); //unload library

    return 0;
}
/*
this is a different approach

gcc main_dynamic.c -o main_dynamic -ldl  # Link with libdl
./main_dynamic
*/