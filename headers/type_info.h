#pragma once
#include "matrix.h"
#include "type_int.h"
#include "type_double.h"
// TODO: errors enum move here
// TODO: maybe create errors_struct, where will pointers on fucntions ?
// TODO: проверку типов лучше сделать как метод type_info
// TODO: выводящая функция не должна ничего знать о том как используется выводимы тип данных
// TODO: неудобный способ обработки ошибок, возвращать код ошибки прикрутить к ней логику какую - нибудь
// TODO: статическую переменную, с состоянием каким - то, которое не даёт проводить дальнейшие операция до восстановления, с получением кода об ошибке
// TODO: заполнение матрицы массивом

typedef enum errors
{
    INCORRECT_FORMAT_OF_MATRIX,
    INCORRECT_INPUT,
    INCORRECT_OPERATION,
    MEMORY_ERROR,
    MATRIX_IS_NULL,
    INCORRECT_TYPE,
    MATRIX_DATA_IS_NULL
} code_errors;

typedef enum types
{
    INT,
    DOUBLE
} types;

typedef void (*math_operation)(const void *num_one, const void *num_two, void *result);
typedef void (*print_num)(void *num);
typedef void (*read_num)(void *num);
typedef void (*swap)(const void *num_one, const void *num_two);
typedef enum types (*check_type)();
typedef size_t (*get_size)();

typedef struct type_info
{
    math_operation sum;
    math_operation multiplication;
    print_num print;
    read_num read;
    swap swap;
    check_type type;
    get_size get_size;
} type_info;