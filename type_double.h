#pragma once
#include "matrix.h"

const struct type_info *get_type_double(matrix *matrix);
void get_float_sum(void *num_one, void *num_two, void *result);
void get_float_multiplication(void *num_one, void *num_two, void *result);
void write_double_element(void *element);
void print_double_element(void *element);
size_t get_size_double_element();