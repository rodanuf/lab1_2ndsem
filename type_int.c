#include <stdio.h>
#include "type_int.h"
#include "type_info.h"

void get_int_type(matrix *matrix)
{
    if (matrix != NULL)
    {
        matrix->type_info = malloc(sizeof(type_info));
        matrix->type_info->sum_el = get_sum;
        matrix->type_info->multiplication_num = get_multiplication;
    }
    else
    {
        printf("matrix doesn't exist!");
    }
}
void get_sum(void *num_one, void *num_two, void *result)
{
    *(int *)result = *(int *)num_one + *(int *)num_two;
}
void get_multiplication(void *num_one, void *num_two, void *result)
{
    *(int *)result = *(int *)num_one * *(int *)num_two;
}