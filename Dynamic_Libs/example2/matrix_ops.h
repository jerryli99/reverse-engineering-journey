//matrix_ops.h - C-compatible header for C++ usage
#ifndef MATRIX_OPS_H
#define MATRIX_OPS_H

#ifdef __cplusplus
extern "C" {
#endif

//Opaque pointer to hide matrix implementation
typedef struct Matrix Matrix;

//Matrix creation/destruction
Matrix* creat_mat(int rows, int cols);
void delete_mat(Matrix* mat);

//basic operations
void mat_add(const Matrix* mat_a, const Matrix* mat_b, Matrix* result);
void mat_mul(const Matrix* mat_a, const Matrix* mat_b, Matrix* result);
double mat_dot(const Matrix* mat_a, const Matrix* mat_b);

//accessors
int mat_rows(const Matrix* mat);
int mat_cols(const Matrix* mat);
double mat_get(const Matrix* mat, int pos_i, int pos_j);
void mat_set(Matrix* mat, int pos_i, int pos_j, double val);


#ifdef __cplusplus
}
#endif

#endif //MATRIX_OPS_H