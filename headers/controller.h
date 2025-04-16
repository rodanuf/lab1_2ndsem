#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "matrix.h"

void scan_string(char *string, int *line, int *column);
void multiple_choice(int choice);
void write_value_into_matrix(matrix *matrix, int c_lines, int n_columns);
void *scan_value(int c_lines, int n_columns);
// TODO: create function array into matrix
// TODO: maybe make function, which would create a array with user data?