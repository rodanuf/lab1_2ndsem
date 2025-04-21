#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "matrix.h"

void scan_size(char *string, int *line, int *column);
void multiple_choice(int choice);
void write_value_into_matrix(matrix *matrix, int c_lines, int n_columns);
void template_matrix(matrix *matrix_sample, matrix *new_matrix);
void *read_array(matrix *matrix);
void clean_buffer();
void check_exit(char * string);
matrix *get_consol_iteraction();
// TODO: create function array into matrix
// TODO: maybe make function, which would create a array with user data?