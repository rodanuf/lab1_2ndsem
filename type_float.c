#include <stdio.h>
#include <stdlib.h>
#include "type_info.h"
#include "type_float.h"

void get_float_sum(void *num_one, void *num_two, void *result)
{
    *(float *)result = *(float *)num_one + *(float *)num_two;
}
void get_float_multiplication(void *num_one, void *num_two, void *result)
{
    *(float *)result = *(float *)num_one * *(float *)num_two;
}

void get_type_float(matrix *matrix)
{
    if (matrix != NULL)
    {
        matrix->type_info = malloc(sizeof(float));
        matrix->type_info->sum_num = get_float_sum;
        matrix->type_info->multiplication_num = get_float_multiplication;
    }
    else
    {
        printf("matrix doesn't exist!");
    }
}