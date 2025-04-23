#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct matrix
    {
        void *element;
        int rows;
        int columns;
        const struct type_info *type_info;
    } matrix;

    matrix *create_matrix();
    void sum_matrix(matrix *matrix1, matrix *matrix2, matrix *m_result);
    void multiply_matrix(matrix *matrix1, matrix *matrix2, matrix *m_result);
    void *get_element(int row_index, int column_index, matrix *matrix);
    void print_matrix(matrix *matrix);
    void transpose_matrix(matrix *matrix);
    void write_array_into_matrix(matrix *matrix, void *array);
    void linear_combination_of_lines(matrix *matrix, int target_row, void *coefficients);

#ifdef __cplusplus
}
#endif