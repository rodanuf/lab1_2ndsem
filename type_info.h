#pragma once

typedef struct type_info_t
{
    void (*sum_num)(void *num_one, void *num_two, void *result);
    void (*multiplication_num)(void *num_one, void *num_two, void *result);
    size_t (*get_size)();
} type_info;