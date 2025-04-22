#pragma once
#include "type_info.h"
#include "matrix.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#ifdef __cplusplus
extern "C"
{
#endif

    void check_matrices_same(matrix *matrix1, matrix *matrix2, type_error *error_handing);
    void check_matrix_null(matrix *matrix, type_error *error_handing);
    void check_correct_format(matrix *matrix, type_error *error_handing);
    void check_correct_size(int size, type_error *error_handing);
    void check_correct_type(char *string, type_error *error_handing);
    void check_data_matrix_null(matrix *matrix, type_error *error_handing);

#ifdef __cplusplus
}
#endif