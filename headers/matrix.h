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
// избавиться от matrix*
// обЪект как константа с ленивой инициализацией
matrix *create_matrix();
// create new ptr;
void get_sum_matrix(matrix *matrix_one, matrix *matrix_two);
void get_multiplication_matrix(matrix *matrix_one, matrix *matrix_two);
void *get_needed_element(int line_index, int column_index, matrix *matrix);
void *get_increment_element(matrix *matrix);
void *get_decrement_element(matrix *matrix, void *element);
void print_matrix(matrix *matrix);
void transport_matrix(matrix *matrix);
void write_array_matrix(matrix *matrix, void *array);
void sum_of_string(matrix *matrix, int num_of_line_one, int num_of_line_two, void *coefficient);