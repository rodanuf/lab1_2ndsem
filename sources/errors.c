#include <stdio.h>
#include "../headers/errors.h"
#include "../headers/type_double.h"

void check_matrices_same(matrix *matrix1, matrix *matrix2, type_error *error_handing)
{
    if (matrix1->type_info != matrix2->type_info ||
        matrix1->columns != matrix2->columns ||
        matrix1->rows != matrix2->rows)
    {
        error_handing->error = INCORRECT_OPERATION;
        error_handing->message = "Incorrect operation: matrices aren't same";
    }
}

void check_correct_format(matrix *matrix, type_error *error_handing)
{
    if (matrix->rows != matrix->columns)
    {
        error_handing->error = INCORRECT_FORMAT_OF_MATRIX;
        error_handing->message = "Incorrect format of matrix: count of rows aren't same count of columns";
    }
}

void check_correct_size(int size, type_error *error_handing)
{
    if (size % 2 != 0)
    {
        error_handing->error = INCORRECT_FORMAT_OF_MATRIX;
        error_handing->message = "Incorrect format of matrix: size must "; // TODO: write here
    }
}

void check_correct_type(char *string, type_error *error_handing)
{
    if (strcmp(string, "double") != 0 && strcmp(string, "integer") != 0)
    {
        error_handing->error = INCORRECT_TYPE;
        error_handing->message = "Incorrect type";
    }
}

void check_matrix_null(matrix *matrix, type_error *error_handing)
{
    if (matrix == NULL)
    {
        error_handing->error = MATRIX_IS_NULL;
        error_handing->message = "Matrix is null";
    }
}

void check_correct_input(const char *string, matrix *matrix, type_error *type_handing)
{
    int cnumber = 0;
    int cdots = 0;
    while (*string != '\0')
    {
        if (!(isdigit(*string)))
        {
            if (*string == '.')
            {
                cdots++;
                if (matrix->type_info != get_double_type())
                {
                    type_handing->error = INCORRECT_INPUT;
                    type_handing->message = "Incorrect input: entered value must with same type with matrix"; // TODO: check with google translate
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
    if (cnumber == 0)
    {
        type_handing->error = INCORRECT_INPUT;
        type_handing->message = "Incorrect input: matrix can only read a numbers";
    }
    if (cdots == 0 && matrix->type_info == get_double_type())
    {
        type_handing->error = INCORRECT_INPUT;
        type_handing->message = "Incorrect input: a double number must have дробную часть"; // TODO: write
    }
    if (cdots == cnumber && matrix->type_info == get_double_type())
    {
        type_handing->error = INCORRECT_INPUT;
        type_handing->message = "Incorrect input: a double number must have дробную часть"; // TODO: write
    }
}

void check_data_matrix_null(matrix *matrix, type_error *error_handing)
{
    if (matrix->element == NULL)
    {
        error_handing->error = MATRIX_DATA_IS_NULL;
        error_handing->message = "Matrix data is NULL";
    }
}