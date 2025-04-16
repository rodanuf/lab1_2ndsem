#pragma once
#include "type_info.h"
#include <string.h>
#include <stdbool.h>

void print_error(code_errors error);
bool is_matrixs_same(matrix *matrix1, matrix *matrix2);
bool is_matrix_null(matrix *matrix);
bool is_correct_format(matrix *matrix);
bool is_correct_size(int size);
bool is_correct_type(char *string);
bool is_correct_input(const char *string, matrix *matrix);
bool is_data_matrix_null(matrix *matrix);