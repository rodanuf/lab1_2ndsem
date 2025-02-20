#include <stdio.h>
#include <stdlib.h>

typedef struct matrix_t
{
    int** int_el;
    float** float_el;
    int string;
    int column;
} matrix;
matrix* create_matrix(int string, int column);
void push_int_el(int el, matrix* matrix, int string_indx, int column_indx);
void push_float_el(float el, matrix* matrix, int string_indx, int column_indx);
void del(matrix* matrix, int string_indx, int column_indx);