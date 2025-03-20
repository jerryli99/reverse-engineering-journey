#include <stdio.h>
#include <stdint.h>

int main()
{
    int x = 42;
    void* ptr;

    ptr = &x;
    printf("Value of x: %d\n", *(int8_t*)ptr);
    printf("Value of x: %d\n", *(int16_t*)ptr);
    printf("Value of x: %d\n", *(int32_t*)ptr);
    printf("Value of x: %ld\n", *(int64_t*)ptr);
    x = -x;
    printf("Value of x: %d\n", *(uint8_t*)ptr);
    printf("Value of x: %d\n", *(uint16_t*)ptr);
    printf("Value of x: %d\n", *(uint32_t*)ptr);
    printf("Value of x: %ld\n", *(uint64_t*)ptr);

    printf("Value of x: %f\n", *(float*)ptr);
    printf("Value of x: %f\n", *(double*)ptr);
    
    ptr = NULL;

    float y = 3.14;
    ptr = &y;
    printf("Value of y: %d\n", *(int8_t*)ptr);
    printf("Value of y: %d\n", *(int16_t*)ptr);
    printf("Value of y: %d\n", *(int32_t*)ptr);
    printf("Value of y: %ld\n", *(int64_t*)ptr);

    y = -y;
    printf("Value of y: %d\n", *(uint8_t*)ptr);
    printf("Value of y: %d\n", *(uint16_t*)ptr);
    printf("Value of y: %d\n", *(uint32_t*)ptr);
    printf("Value of y: %ld\n", *(uint64_t*)ptr);

    printf("Value of y: %f\n", *(float*)ptr);
    printf("Value of y: %f\n", *(double*)ptr);

    ptr = NULL;
    double z = 1239;
    ptr = &z;

    printf("Value of z: %d\n", *(int8_t*)ptr);
    printf("Value of z: %d\n", *(int16_t*)ptr);
    printf("Value of z: %d\n", *(int32_t*)ptr);
    printf("Value of z: %ld\n", *(int64_t*)ptr);

    z = -z;
    printf("Value of z: %d\n", *(uint8_t*)ptr);
    printf("Value of z: %d\n", *(uint16_t*)ptr);
    printf("Value of z: %d\n", *(uint32_t*)ptr);
    printf("Value of z: %ld\n", *(uint64_t*)ptr);

    printf("Value of z: %f\n", *(float*)ptr);
    printf("Value of z: %f\n", *(double*)ptr);

    return (0);
}