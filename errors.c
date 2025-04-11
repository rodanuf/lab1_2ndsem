#include <stdio.h>
#include "errors.h"

void print_error(int error)
{
    switch (error)
    {
    case INCORRECT_FORMAT_OF_MATRIX:
        printf("Incorrect format of matrix\n");
        break;
    case INCORRECT_INPUT:
        printf("Incorrect input\n");
        break;
    case INCORREXT_OPERATION:
        printf("Incorrect operation\n");
        break;
    case MEMORY_ERROR:
        printf("Memory error\n");
        break;
    case MATRIX_IS_NULL:
        printf("Matrix is null\n");
        break;
    default:
        break;
    }
}
