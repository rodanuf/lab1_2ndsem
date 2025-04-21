#include <stdio.h>
#include "../headers/matrix.h"
#include "../headers/type_info.h"
#include "../headers/errors.h"
#include "../headers/type_int.h"
#include "../headers/type_int_functions.h"

void get_int_sum(const void *num_one, const void *num_two, void *result)
{
    int *a = (int *)num_one;
    int *b = (int *)num_two;
    *(int *)result = (*a) + (*b);
}

void get_int_multiplication(const void *num_one, const void *num_two, void *result)
{
    int *a = (int *)num_one;
    int *b = (int *)num_two;
    *(int *)result = (*a) * (*b);
}

void print_int_element(void *element)
{
    printf("%d ", *(int *)element);
}

void read_int_element(void *element)
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
    *(int *)element = (int)strtol(result, &remainder, 10);
    free(result);
    free (remainder);
}

void swap_int_elements(void *element_one, void *element_two)
{
    int temp = *(int *)element_one;
    *(int *)element_one = *(int *)element_two;
    *(int *)element_two = temp;
}

size_t get_size_int_element()
{
    return sizeof(int);
}

static struct type_info *type_p = NULL;

const struct type_info *get_int_type()
{
    if (type_p == NULL)
    {
        type_p = malloc(sizeof(type_info));
        type_p->sum = get_int_sum;
        type_p->multiplication = get_int_multiplication;
        type_p->print = print_int_element;
        type_p->read = read_int_element;
        type_p->swap = swap_int_elements;
        type_p->get_size = get_size_int_element;
    }
    return type_p;
}