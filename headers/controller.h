#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "matrix.h"
#include "errors.h"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct result_info
    {
        matrix *m_result;
        bool is_succses;
        type_error *error_handing;
    } result_info;

    result_info *create_result_info();
    void scan_size(char *string, int *line, int *column, result_info *result);
    void multiple_choice(int choice);
    void write_value_into_matrix(matrix *matrix, int c_lines, int n_columns, result_info *result);
    void giving_data_type_to_matrix(matrix *matrix, result_info *result);
    void template_matrix(matrix *matrix_sample, matrix *m_result);
    void *read_array(matrix *matrix, result_info *result);
    void clean_buffer();
    void check_exit(char *string);
    matrix *get_consol_iteraction(result_info *resut);

#ifdef __cplusplus
}
#endif