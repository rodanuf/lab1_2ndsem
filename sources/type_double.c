#include <stdio.h>
#include <stdlib.h>
#include "../headers/type_info.h"
#include "../headers/type_double.h"
#include "../headers/matrix.h"
#include "../headers/errors.h"
#include "../headers/type_double_functions.h"

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
    char buffer[2];
    char *result = NULL;
    size_t result_size = 0;
    while (fgets(buffer, sizeof(buffer), stdin))
    {
        size_t buffer_size = strlen(buffer);
        for (size_t i = 0; i < buffer_size; i++)
        {
            if (buffer[i] == ' ' || buffer[i] == '\n')
            {
                buffer_size = i;
                break;
            }
        }
        result = realloc(result, result_size + buffer_size + 1);
        memcpy(result + result_size, buffer, buffer_size);
        result_size += buffer_size;

        if (buffer[buffer_size] == '\n' || buffer[buffer_size] == ' ')
        {
            break;
        }
    }
    char *remainder;
    *(double *)element = (double)strtod(result, &remainder);
    free(result);
    free(remainder);
}

void swap_double_elements(void *element_one, void *element_two)
{
    double temp = *(double *)element_one;
    *(double *)element_one = *(double *)element_two;
    *(double *)element_two = temp;
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
        type_p->get_size = get_size_double_element;
    }
    return type_p;
}
