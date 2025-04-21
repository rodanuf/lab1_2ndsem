#pragma once
#include "type_info.h"
#include "matrix.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void print_error(input_errors error);
input_errors check_matrices_same(matrix *matrix1, matrix *matrix2);
input_errors check_matrix_null(matrix *matrix);
input_errors check_correct_format(matrix *matrix);
input_errors check_correct_size(int size);
input_errors check_correct_type(char *string);
input_errors check_data_matrix_null(matrix *matrix);