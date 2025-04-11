#include <stdio.h>
#include <stdlib.h>
#include "type_info.h"
#include "type_double.h"
#include "errors.h"

// TODO: create alias for functions
void get_float_sum(void *num_one, void *num_two, void *result)
{
    *(float *)result = *(float *)num_one + *(float *)num_two;
}
void get_float_multiplication(void *num_one, void *num_two, void *result)
{
    *(float *)result = *(float *)num_one * *(float *)num_two;
}
size_t get_size_double_element()
{
    return sizeof(double);
}
void print_double_element(void *element)
{
    printf("%lf ", *(double *)element);
}
void write_double_element(void *element_ptr)
{
    double num;
    scanf("%lf", &num);
    *(double *)element_ptr = num;
}
const type_info *get_double_type(matrix *matrix)
{
    if (matrix != NULL)
    {
        if (matrix->type_info == NULL)
        {
            matrix->type_info = malloc(sizeof(type_info));
            matrix->type_info->sum_num = get_float_sum;
            matrix->type_info->multiplication_num = get_float_multiplication;
            matrix->type_info->get_size = get_size_double_element;
            matrix->type_info->print_num = print_double_element;
            matrix->type_info->write_num = write_double_element;
            return matrix->type_info;
        }
    }
    else
    {
        print_errors(MATRIX_IS_NULL);
    }
}