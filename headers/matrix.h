#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "type_info.h"

typedef struct matrix
{
    void *element;
    int lines;
    int columns;
    const struct type_info *type_info;
} matrix;
matrix *create_matrix();
void get_sum_matrix(matrix *matrix1, matrix *matrix2, matrix *m_result);
void get_multiplication_matrix(matrix *matrix1, matrix *matrix2, matrix *ma_result);
void *get_needed_element(int line_index, int column_index, matrix *matrix);
void *get_increment_element(matrix *matrix, void *ptr_element);
void *get_decrement_element(matrix *matrix, void *ptr_element);
void print_matrix(matrix *matrix);
void transpose_matrix(matrix *originally_matrix, matrix *matrix_result);
void write_array_matrix(matrix *matrix, void *ptr_array);
void linear_combination_of_lines(matrix *matrix, int index, void *ptr_array);