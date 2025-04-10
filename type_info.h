#pragma once
#include "type_int.h"
#include "type_double.h"

typedef struct type_info_t
{
    void (*sum_num)(void *num_one, void *num_two, void *result);
    void (*multiplication_num)(void *num_one, void *num_two, void *result);
    void (*print_num)(void *num);
    size_t (*get_size)();
} type_info;