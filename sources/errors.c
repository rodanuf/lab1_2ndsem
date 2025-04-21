#include <stdio.h>
#include "../headers/errors.h"

void print_error(input_errors error)
{
    switch (error)
    {
    case INCORRECT_FORMAT_OF_MATRIX:
        printf("Incorrect format of matrix\n");
        break;
    case INCORRECT_INPUT:
        printf("Incorrect input\n");
        break;
    case MEMORY_ERROR:
        printf("Memory error\n");
        break;
    case INCORRECT_TYPE:
        printf("Incorrect data type\n");
        break;
    default:
        break;
    }
}
///// TODO: return code_error, if it
///code_errors check_matrices_same(matrix *matrix1, matrix *matrix2)
///{
///    if (matrix1->type_info->type != matrix2->type_info->type ||
///        matrix1->columns != matrix2->columns ||
///        matrix1->lines != matrix2->lines)
///    {
///        return INCORRECT_OPERATION;
///    }
///    return -1;
///}
input_errors check_correct_format(matrix *matrix)
{
    if (matrix->rows != matrix->columns)
    {
        return INCORRECT_FORMAT_OF_MATRIX;
    }
    return -1;
}
input_errors check_correct_size(int size)
{
    if (size % 2 != 0)
    {
        return INCORRECT_FORMAT_OF_MATRIX;
    }
    return -1;
}
input_errors check_correct_type(char *string)
{
    if (strcmp(string, "double") != 0 && strcmp(string, "integer") != 0)
    {
        return INCORRECT_TYPE;
    }
    return -1;
}
input_errors check_matrix_null(matrix *matrix)
{
    if (matrix == NULL)
    {
        return MATRIX_IS_NULL;
    }
    return -1;
}
//code_errors check_correct_input(const char *string, check_type type)
//{
//    int cnumber = 0;
//    int cdots = 0;
//    while (*string != '\0')
//    {
//
//        if (!(isdigit(*string)))
//        {
//            if (*string == '.')
//            {
//                cdots++;
//                if (type() != 1)
//                {
//                    return INCORRECT_INPUT;
//                }
//            }
//            else
//            {
//                string++;
//            }
//        }
//        else
//        {
//            cnumber++;
//            string++;
//        }
//    }
//    if (cnumber == 0)
//    {
//        return INCORRECT_INPUT;
//    }
//    if (cdots == 0 && type() == 1)
//    {
//        return INCORRECT_INPUT;
//    }
//    if (cdots == cnumber && type() == 1)
//    {
//        return INCORRECT_INPUT;
//    }
//    return -1;
//}
input_errors check_data_matrix_null(matrix *matrix)
{
    if (matrix->element == NULL)
    {
        return MATRIX_DATA_IS_NULL;
    }
    return -1;
}