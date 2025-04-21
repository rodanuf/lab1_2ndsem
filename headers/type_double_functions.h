#pragma once
#include <stdio.h>
#include "matrix.h"
#include "type_info.h"
#include "type_double.h"

void sum_double(const void *num_one, const void *num_two, void *result);
void multiply_double(const void *num_one, const void *num_two, void *result);
void read_double_element(void *element);
void print_double_element(void *element);
void swap_double_elements(void *element_one, void *element_two);
size_t get_size_double_element();