#include <stdio.h>
#include <stdlib.h>
#include "../headers/type_info.h"
#include "../headers/type_double.h"
#include "../headers/matrix.h"
#include "../headers/errors.h"

// TODO: create alias for functions
void get_double_sum(const void *num_one, const void *num_two, void *result)
{
    double *a = (double *)num_one;
    double *b = (double *)num_two;
    *(double *)result = (*a) + (*b);
}
void get_double_multiplication(const void *num_one, const void *num_two, void *result)
{
    double *a = (double *)num_one;
    double *b = (double *)num_two;
    *(double *)result = (*a) * (*b);
}
size_t get_size_double_element()
{
    return sizeof(double);
}
void print_double_element(void *element)
{
    printf("%.2lf ", *(double *)element);
}
void read_double_element(void *element)
{
    char input[10];
    scanf("%s", &input);
    print_error(check_correct_input(input, return_double_type));
    *(double *)element = strtol(input, NULL, 10);
}
void swap_double_elements(void *element_one, void *element_two)
{
    double temp = *(double *)element_one;
    *(double *)element_one = *(double *)element_two;
    *(double *)element_two = temp;
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
        type_p->sum = get_double_sum;
        type_p->multiplication = get_double_multiplication;
        type_p->get_size = get_size_double_element;
        type_p->print = print_double_element;
        type_p->read = read_double_element;
        type_p->swap = swap_double_elements;
        type_p->type = return_double_type;
        type_p->get_size = get_size_double_element;
    }
    return type_p;
}
