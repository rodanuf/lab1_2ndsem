#pragma once
#include "matrix.h"
#include "type_info.h"

const struct type_info *get_int_type();
void get_int_sum(void *num_one, void *num_two, void *result);
void get_int_multiplication(void *num_one, void *num_two, void *result);
void print_int_element(void *element);
enum types return_int_type();
size_t get_size_int_element();