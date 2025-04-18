#pragma once
#include "type_info.h"
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
// TODO: enum error_type convert into struct, where would ptr on int error functions< which would return ptr on argument functions;
void print_error(code_errors error);
code_errors check_matrices_same(matrix *matrix1, matrix *matrix2);
code_errors check_matrix_null(matrix *matrix);
code_errors check_correct_format(matrix *matrix);
code_errors check_correct_size(int size);
code_errors check_correct_type(char *string);
code_errors check_correct_input(const char *string, check_type type);
code_errors check_data_matrix_null(matrix *matrix);