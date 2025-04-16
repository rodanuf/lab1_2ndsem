#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "matrix.h"

void scan_string(char *string, int *line, int *column);
void multiple_choice(int choice);
// TODO: move into matrix
void write_value_into_matrix(matrix *matrix);
// TODO: create function array into matrix