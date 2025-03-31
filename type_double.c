#include <stdio.h>
#include <stdlib.h>
#include "type_info.h"
#include "type_double.h"

void get_float_sum(void *num_one, void *num_two, void *result)
{
    *(float *)result = *(float *)num_one + *(float *)num_two;
}
void get_float_multiplication(void *num_one, void *num_two, void *result)
{
    *(float *)result = *(float *)num_one * *(float *)num_two;
}
size_t get_size_double_el()
{
    return sizeof(double);
}
void get_type_float(matrix *matrix)
{
    if (matrix != NULL)
    {
        matrix->type_info = malloc(sizeof(type_info));
        matrix->type_info->sum_num = get_float_sum;
        matrix->type_info->multiplication_num = get_float_multiplication;
        matrix->type_info->get_size = get_size_double_el;
    }
    else
    {
        printf("matrix doesn't exist!");
    }
}