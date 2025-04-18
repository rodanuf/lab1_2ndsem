#pragma once
#include "matrix.h"
#include "type_info.h"

const struct type_info *get_int_type();
void get_int_sum(const void *num_one, const void *num_two, void *result);
void get_int_multiplication(const void *num_one, const void *num_two, void *result);
void print_int_element(void *element);
void swap_int_elements(void *element_one, void *element_two);
enum types return_int_type();
size_t get_size_int_element();