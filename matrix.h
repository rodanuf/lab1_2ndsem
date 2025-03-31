#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "type_info.h"
typedef struct matrix_t
{
    void *el;
    int count_of_string;
    int count_of_column;
    type_info *type_info
} matrix;
// избавиться от matrix*
// обЪект как константа с ленивой инициализацией
matrix *generate_double_matrix(int string, int column);
matrix *generate_int_matrix(int string, int column);
matrix *create_matrix(int string, int column);
void get_sum_matrix(matrix *matrix_one, matrix *matrix_two);
void get_multiplication_matrix(matrix *matrix_one, matrix *matrix_two);
void get_needed_el(int string_index, int column_index, matrix *matrix);
void get_increment_el(matrix *matrix);
void print_matrix(matrix *matrix);