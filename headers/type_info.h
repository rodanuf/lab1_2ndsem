#pragma once

typedef enum input_errors
{
    INCORRECT_FORMAT_OF_MATRIX,
    INCORRECT_INPUT,
    MEMORY_ERROR,
    INCORRECT_TYPE,
} input_errors;

typedef enum matrix_errors
{
    MATRIX_DATA_IS_NULL,
    INCORRECT_OPERATION,
    MATRIX_IS_NULL
} matrix_errors;

typedef void (*math_operation)(const void *operand_one, const void *operand_rwo, void *result);
typedef void (*print_num)(void *num);
typedef void (*read_num)(void *num);
typedef void (*swap)(void *operand_one, void *operand_two);
typedef size_t (*get_size)();

typedef struct type_info
{
    math_operation sum;
    math_operation multiplication;
    print_num print;
    read_num read;
    swap swap;
    get_size get_size;
} type_info;