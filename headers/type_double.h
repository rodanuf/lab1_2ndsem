#pragma once
#include "matrix.h"
#include "type_info.h"

const struct type_info *get_double_type(matrix *matrix);
void get_float_sum(void *num_one, void *num_two, void *result);
void get_float_multiplication(void *num_one, void *num_two, void *result);
void read_double_element(void *element);
void print_double_element(void *element);
enum types get_type();
size_t get_size_double_element();