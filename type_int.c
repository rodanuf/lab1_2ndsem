#include <stdio.h>
#include "type_int.h"
#include "type_info.h"

void get_sum(void *num_one, void *num_two, void *result)
{
    *(int *)result = *(int *)num_one + *(int *)num_two;
}
void get_multiplication(void *num_one, void *num_two, void *result)
{
    *(int *)result = *(int *)num_one * *(int *)num_two;
}

size_t get_size_int_el()
{
    return sizeof(int);
}
void get_int_type(matrix *matrix)
{
    if (matrix != NULL)
    {
        matrix->type_info = malloc(sizeof(type_info));
        matrix->type_info->sum_num = get_sum;
        matrix->type_info->multiplication_num = get_multiplication;
        matrix->type_info->get_size = get_size_int_el;
    }
    else
    {
        printf("matrix doesn't exist!");
    }
}