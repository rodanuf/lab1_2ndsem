#include <stdio.h>
#include "../headers/errors.h"

void print_error(code_errors error)
{
    switch (error)
    {
    case INCORRECT_FORMAT_OF_MATRIX:
        printf("Incorrect format of matrix\n");
        break;
    case INCORRECT_INPUT:
        printf("Incorrect input\n");
        break;
    case INCORRECT_OPERATION:
        printf("Incorrect operation\n");
        break;
    case MEMORY_ERROR:
        printf("Memory error\n");
        break;
    case MATRIX_IS_NULL:
        printf("Matrix is null\n");
        break;
    case INCORRECT_TYPE:
        printf("Incorrect data type\n");
    default:
        break;
    }
}
///// TODO: return code_error, if it
bool is_matrixs_same(matrix *matrix1, matrix *matrix2)
{
    if (matrix1->type_info->type == matrix2->type_info->type)
    {
        return true;
    }
    print_error(INCORRECT_OPERATION);
    return false;
}
bool is_correct_format(matrix *matrix)
{
    if (matrix->lines == matrix->columns)
    {
        return true;
    }
    print_error(INCORRECT_FORMAT_OF_MATRIX);
    return false;
}
bool is_correct_size(int size)
{
    if (size % 2 == 0)
    {
        return true;
    }
    print_error(INCORRECT_FORMAT_OF_MATRIX);
    return false;
}
bool is_correct_type(char *string)
{
    if (strcmp(string, "double") == 0 && strcmp(string, "integer") == 0)
    {
        return true;
    }
    print_error(INCORRECT_TYPE);
    return false;
}
bool is_matrix_null(matrix *matrix)
{
    if (matrix == NULL)
    {
        return true;
    }
    print_error(MATRIX_IS_NULL);
    return false;
}
bool is_correct_input(const char *string, matrix *matrix)
{
    int cnumber = 0;
    while (*string != '\0')
    {

        if (!(isdigit(*string)))
        {
            if (*string == '.')
            {
                if (matrix->type_info->type == 1)
                {
                    return true;
                }
                else
                {
                    print_error(INCORRECT_INPUT);
                    return false;
                }
            }
            else
            {
                string++;
            }
        }
        else
        {
            cnumber++;
            string++;
        }
    }
    if (cnumber != 0)
    {
        return true;
    }
    print_error(INCORRECT_INPUT);
    return false;
}