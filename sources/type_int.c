#include <stdio.h>
#include "../headers/matrix.h"
#include "../headers/type_info.h"
#include "../headers/errors.h"

void get_int_sum(void *num_one, void *num_two, void *result)
{
    *(int *)result = *(int *)num_one + *(int *)num_two;
}
void get_int_multiplication(void *num_one, void *num_two, void *result)
{
    *(int *)result = *(int *)num_one * *(int *)num_two;
}
void print_int_element(void *element)
{
    printf("%d ", *(int *)element);
}
void read_int_element(void *element)
{
    int num;
    scanf("%d", &num);
    *(int *)element = num;
}
types return_int_type()
{
    return INT;
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
        type_p->type = return_int_type;
        type_p->get_size = get_size_int_element;
        return type_p;
    }
    else
    {
        return type_p;
    }
}