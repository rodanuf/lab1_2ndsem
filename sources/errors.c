#include <stdio.h>
#include "../headers/errors.h"
#include "../headers/type_double.h"

type_error *get_success_result()
{
    type_error *s_error = malloc(sizeof(type_error));
    s_error->error = -1;
    s_error->message = "Successful execution";
    return s_error;
}

void check_matrices_same(matrix *matrix1, matrix *matrix2, type_error *error_handing)
{
    if (matrix1->type_info != matrix2->type_info ||
        matrix1->columns != matrix2->columns ||
        matrix1->rows != matrix2->rows)
    {
        error_handing->error = INCORRECT_OPERATION;
        error_handing->message = "Incorrect operation: matrices aren't same";
    }
    else
    {
        error_handing->error = -1;
        error_handing->message = "Successful execution";
    }
}

void check_correct_size(char *string, type_error *error_handing)
{
    error_handing->error = -1;
    error_handing->message = "Succesfull execution";
    while (*string != '\0')
    {
        if (!(isdigit(*string)))
        {
            error_handing->error = INCORRECT_INPUT;
            error_handing->message = "Size must be a natural number";
        }
        string++;
    }
}

void check_correct_type(char *string, type_error *error_handing)
{
    if (strcmp(string, "double") != 0 && strcmp(string, "integer") != 0)
    {
        error_handing->error = INCORRECT_TYPE;
        error_handing->message = "Incorrect type";
    }
    else
    {
        error_handing->error = -1;
        error_handing->message = "Succesfull execution";
    }
}

void check_correct_input(const char *string, matrix *matrix, type_error *error_handing)
{
    error_handing->error = -1;
    error_handing->message = "Succesfull execution";
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
                    error_handing->error = INCORRECT_INPUT;
                    error_handing->message = "Incorrect input: entered value must with same type as matrix";
                }
            }
        }
        else
        {
            cnumber++;
        }
        string++;
    }
    if (cnumber == 0)
    {
        error_handing->error = INCORRECT_INPUT;
        error_handing->message = "Incorrect input: matrix can only read a numbers";
    }
    if (cdots == 0 && matrix->type_info == get_double_type())
    {
        error_handing->error = INCORRECT_INPUT;
        error_handing->message = "Incorrect input: a double number must have fractional part";
    }
    if (cdots == cnumber && matrix->type_info == get_double_type())
    {
        error_handing->error = INCORRECT_INPUT;
        error_handing->message = "Incorrect input: a double number must have fractional part";
    }
}

void check_data_matrix_null(matrix *matrix, type_error *error_handing)
{
    if (matrix->element == NULL)
    {
        error_handing->error = MATRIX_DATA_IS_NULL;
        error_handing->message = "Matrix data is NULL";
    }
    else
    {
        error_handing->error = -1;
        error_handing->message = "Succesfull execution";
    }
}