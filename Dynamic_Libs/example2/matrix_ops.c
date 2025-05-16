// matrix_ops.c - Library implementation
#include "matrix_ops.h"
#include <stdlib.h>
#include <string.h>

// Hidden matrix structure
struct Matrix {
    int rows, cols;
    double* data;
};

Matrix* create_mat(int rows, int cols) {
    Matrix* mat = malloc(sizeof(Matrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = calloc(rows * cols, sizeof(double));
    return mat;
}

void delete_mat(Matrix* mat) {
    free(mat->data);
    free(mat);
}

// ... Implement other operations (add, mul, dot, etc.) ...
void mat_add(const Matrix* a, const Matrix* b, Matrix* result) {
    for (int i = 0; i < a->rows * a->cols; i++) {
        result->data[i] = a->data[i] + b->data[i];
    }
}

double mat_dot(const Matrix* a, const Matrix* b) {
    double sum = 0.0;
    for (int i = 0; i < a->rows * a->cols; i++) {
        sum += a->data[i] * b->data[i];
    }
    return sum;
}

/*
gcc -fPIC -c matrix_ops.c -o matrix_ops.o
gcc -shared -o libmatrix.so matrix_ops.o
*/