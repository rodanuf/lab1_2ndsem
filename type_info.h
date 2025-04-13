#pragma once
#include "type_int.h"
#include "type_double.h"
// TODO: errors enum move here
// TODO: maybe create errors_struct, where will pointers on fucntions ?
// TODO: проверку типов лучше сделать как метод type_info
// TODO: выводящая функция не должна ничего знать о том как используется выводимы тип данных
// TODO: неудобный способ обработки ошибок, возвращать код ошибки прикрутить к ней логику какую - нибудь
// статическую переменную, с состоянием каким - то, которое не даёт проводить дальнейшие операция до восстановления, с получением кода об ошибке
// TODO: заполнение матрицы массивом

typedef enum
{
    INCORRECT_FORMAT_OF_MATRIX = 1,
    INCORRECT_INPUT = 2,
    INCORRECT_OPERATION = 3,
    MEMORY_ERROR = 4,
    MATRIX_IS_NULL = 5
} code_errors;

typedef struct type_info_t
{
    void (*sum_num)(void *num_one, void *num_two, void *result);
    void (*multiplication_num)(void *num_one, void *num_two, void *result);
    void (*print_num)(void *num);
    void (*write_num)(void *num);
    size_t (*get_size)();
} type_info;