#pragma once
#include "type_int.h"
#include "matrix.h"
#include "type_info.h"

#ifdef __cplusplus
extern "C"
{
#endif

    void get_int_sum(const void *num_one, const void *num_two, void *result);
    void get_int_multiplication(const void *num_one, const void *num_two, void *result);
    void read_int_element(void *element, matrix *matrix, type_error *error_handing);
    void print_int_element(void *element);
    void swap_int_elements(void *element_one, void *element_two);
    size_t get_size_int_element();

#ifdef __cplusplus
}
#endif