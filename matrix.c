#include "matrix.h"

matrix *create_matrix(int string, int column, int type_of_matrix)
{
    matrix *matrix_ptr = malloc(sizeof(matrix));
    matrix_ptr->count_of_string = string;
    matrix_ptr->count_of_column = column;
    matrix_ptr->el = malloc(string * column * sizeof(void *));
    if (type_of_matrix == 1)
    {
        get_int_type(matrix_ptr);
    }
    if (type_of_matrix == 0)
    {
        get_double_type(matrix_ptr);
    }
    return matrix_ptr;
}
matrix *generate_matrix(int string, int column)
{
    matrix *matrix_ptr = malloc(sizeof(matrix));
    matrix_ptr->count_of_string = string;
    matrix_ptr->count_of_column = column;
    matrix_ptr->el = malloc(string * column * sizeof(void *));
    return matrix_ptr;
    // rand
}
void get_sum_matrix(matrix *matrix_one, matrix *matrix_two)
{
    if (matrix_one->count_of_string == matrix_two->count_of_string || matrix_one->count_of_column == matrix_two->count_of_column)
    {
        if (matrix_one->type_info == matrix_two->type_info)
        {
            for (int i = 1; i <= (matrix_one->count_of_column * matrix_one->count_of_string); i++)
            {
                matrix_one->type_info->sum_num(matrix_one->el, matrix_two->el, matrix_one->el);
                get_increment_el(matrix_one);
                get_increment_el(matrix_two);
            }
        }
    }
    else
    {
        printf("incorrect format of matrix");
    }
}
void get_multiplication_matrix(matrix *matrix_one, matrix *matrix_two)
{
    if (matrix_one->count_of_string == matrix_two->count_of_string || matrix_one->count_of_column == matrix_two->count_of_column)
    {
        if (matrix_one->type_info == matrix_two->type_info)
        {
            for (int i = 1; i <= (matrix_one->count_of_column * matrix_two->count_of_string); i++)
            {
                matrix_one->type_info->multiplication_num(matrix_one->el, matrix_two->el, matrix_one->el);
                get_increment_el(matrix_one);
                get_increment_el(matrix_two);
            }
        }
    }
    else
    {
        printf("incorrect format of matrix");
    }
}
void get_needed_el(int string_index, int column_index, matrix *matrix)
{
    for (int i = 1; i <= (string_index * column_index); i++)
    {
        get_increment_el(matrix);
    }
    return matrix->el;
}
void get_increment_el(matrix *matrix)
{
    if (matrix->type_info->get_size == 4)
    {
        int *element_ptr = malloc(sizeof(int));
        element_ptr = (int *)matrix->el;
        element_ptr += matrix->type_info->get_size();
        matrix->el = element_ptr;
    }
    if (matrix->type_info->get_size == 8)
    {
        double *element_ptr = malloc(sizeof(double));
        element_ptr = (double *)matrix->el;
        element_ptr += matrix->type_info->get_size();
        matrix->el = element_ptr;
    }
}
void print_matrix(matrix *matrix)
{
    for (int i = 1; (matrix->count_of_column * matrix->count_of_string); i++)
    {
        if (matrix->type_info->get_size == 4)
        {
            printf("%d", *(int *)matrix->el);
            get_increment_el(matrix);
        }
        if (matrix->type_info->get_size == 8)
        {
            printf("%.2f", *(double *)matrix->el);
            get_increment_el(matrix);
        }
    }
}

void transport_matrix(matrix *matrix)
{
    if (matrix != NULL)
    {
        int size_of_el = matrix->type_info->get_size;
        void *element_ptr = malloc(sizeof(void *));
        for (int j = 0; j < (matrix->count_of_column); j++)
        {
            for (int i = 0; i < (matrix->count_of_string); i++)
            {
                if (matrix->type_info->get_size == 4)
                {
                    (int *)element_ptr = element_ptr;
                    element_ptr = (int *)matrix->el + i * matrix->type_info->get_size() + j * matrix->count_of_column * size_of_el;
                    (int *)matrix->el + i * matrix->type_info->get_size() = (int *)matrix->el + i * size_of_el + matrix->count_of_column * size_of_el;
                }
                else
                {
                    (double *)element_ptr = element_ptr;
                    element_ptr = (double *)matrix->el + i * matrix->type_info->get_size() + j * matrix->count_of_column * size_of_el;
                    (double *)matrix->el + i * matrix->type_info->get_size() = (int *)matrix->el + i * size_of_el + matrix->count_of_column * size_of_el;
                }
            }
        }
    }
}

void sum_of_strings(matrix *matrix, int num_of_string_one, int num_of_string_two, void *coefficient)
{
    if (matrix != NULL)
    {
        int size_of_el = matrix->type_info->get_size;
        void *element_ptr = malloc(sizeof(void *));
        if (size_of_el == 4)
        {
            for (int i = 0; i < (matrix->count_of_column); i++)
            {
                int *first_string_ptr = (int *)matrix->el + num_of_string_one * matrix->count_of_column * size_of_el;
                int *second_string_ptr = (int *)matrix->el + num_of_string_two * matrix->count_of_column * size_of_el;
                *first_string_ptr = *(int *)coefficient * *second_string_ptr;
                get_increment_el(matrix);
            }
        }
        else
        {
            double *first_string_ptr = (double *)matrix->el + num_of_string_one * matrix->count_of_column * size_of_el;
            double *second_string_ptr = (double *)matrix->el + num_of_string_two * matrix->count_of_column * size_of_el;
            for (int i = 0; i < (matrix->count_of_column); i++)
            {
                *first_string_ptr = *(double *)coefficient * *second_string_ptr;
                get_increment_el(matrix);
            }
        }
    }
}