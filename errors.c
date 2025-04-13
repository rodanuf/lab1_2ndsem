#include <stdio.h>
#include <stdbool.h>
#include "errors.h"

bool print_error(int error)
{
    switch (error)
    {
    case INCORRECT_FORMAT_OF_MATRIX:
        printf("Incorrect format of matrix\n");
        return false;
        break;
    case INCORRECT_INPUT:
        printf("Incorrect input\n");
        return false;
        break;
    case INCORRECT_OPERATION:
        printf("Incorrect operation\n");
        return false;
        break;
    case MEMORY_ERROR:
        printf("Memory error\n");
        return false;
        break;
    case MATRIX_IS_NULL:
        printf("Matrix is null\n");
        return false;
        break;
    default:
        return true;
        break;
    }
}
///// TODO: return code_error, if it
void compare_matrix(matrix *matrix_one, matrix *matrix_two)
{
    if (matrix_one->lines != matrix_two->lines)
    {
        print_error(INCORRECT_OPERATION);
    }
    if (matrix_one->columns != matrix_two->columns)
    {
        print_error(INCORRECT_OPERATION);
    }
    if (matrix_one->type_info->sum_num != matrix_two->type_info->sum_num)
    {
        print_error(INCORRECT_OPERATION);
    }
    else
    {
        print_error(0);
    }
}
void check_format_of_matrix(matrix *matrix)
{
    if (matrix->lines == matrix->columns)
    {
        print_error(INCORRECT_FORMAT_OF_MATRIX);
    }
}