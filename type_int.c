#include <stdio.h>
#include "type_int.h"
#include "type_info.h"

void get_int_sum(void *num_one, void *num_two)
{
    *(int *)num_one = *(int *)num_one + *(int *)num_two;
}
void get_int_multiplication(void *num_one, void *num_two)
{
    *(int *)num_one = *(int *)num_one * *(int *)num_two;
}
void print_int_element(void *element)
{
    printf("%d ", *(int *)element);
}
size_t get_size_int_el()
{
    return sizeof(int);
}
const type_info *get_int_type(matrix *matrix)
{
    if (matrix != NULL)
    {
        if (matrix->type_info == NULL)
        {
            matrix->type_info = malloc(sizeof(type_info));
            matrix->type_info->sum_num = get_sum;
            matrix->type_info->multiplication_num = get_multiplication;
            matrix->type_info->get_size = get_size_int_element;
            matrix->type_info->print_num = print_int_element;
        }
    }
    else
    {
        printf("matrix doesn't exist!");
    }
}