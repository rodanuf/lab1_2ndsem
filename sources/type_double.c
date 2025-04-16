#include <stdio.h>
#include <stdlib.h>
#include "../headers/type_info.h"
#include "../headers/type_double.h"
#include "../headers/matrix.h"
#include "../headers/errors.h"

// TODO: create alias for functions
void get_float_sum(void *num_one, void *num_two, void *result)
{
    *(double *)result = *(double *)num_one + *(double *)num_two;
}
void get_float_multiplication(void *num_one, void *num_two, void *result)
{
    *(double *)result = *(double *)num_one * *(float *)num_two;
}
size_t get_size_double_element()
{
    return sizeof(double);
}
void print_double_element(void *element)
{
    printf("%lf ", *(double *)element);
}
void read_double_element(void *element_ptr)
{
    scanf("%lf", (double *)element_ptr);
}
types return_double_type()
{
    return DOUBLE;
}

static struct type_info *type_p = NULL;

const struct type_info *get_double_type()
{
    if (type_p == NULL)
    {
        type_p = malloc(sizeof(type_info));
        type_p->sum = get_float_sum;
        type_p->multiplication = get_float_multiplication;
        type_p->get_size = get_size_double_element;
        type_p->print = print_double_element;
        type_p->read = read_double_element;
        type_p->type = return_double_type;
        type_p->get_size = get_size_double_element;
        return type_p;
    }
    else
    {
        return type_p;
    }
}
