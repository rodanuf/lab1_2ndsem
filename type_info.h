#pragma once

typedef struct type_info_t
{
    void (*sum_el)(void *num_one, void *num_two, void *result);
    void (*multiplication_num)(void *num_one, void *num_two, void *result);
} type_info;