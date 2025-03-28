#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "type_info.h"
typedef struct matrix_t
{
    void *el;
    int string;
    int column;
    type_info *type_info
} matrix;
matrix *generate_float_matrix(int string, int column, float el);
matrix *generate_int_matrix(int string, int column, int el);
matrix *create_matrix(int string, int column, int el);
matrix *get_sum_matrix(matrix *matrix_one, matrix *matrix_two);
matrix *get_multiplication_matrix(matrix *matrix_one, matrix *matrix_two);
void get_increment_el(matrix *matrix);