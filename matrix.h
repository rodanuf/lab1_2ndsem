#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "type_info.h"
typedef struct matrix_t
{
    void *el;
    int string;
    int column;
    type_info *type_info
} matrix;
matrix *create_float_matrix(int string, int column, float el);
matrix *create_int_matrix(int string, int column, int el);
