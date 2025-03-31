#include "matrix.h"

matrix *create_matrix(int string, int column)
{
    matrix *matrix_ptr = malloc(sizeof(matrix));
    matrix_ptr->count_of_string = string;
    matrix_ptr->count_of_column = column;
    matrix_ptr->el = malloc(string * column * sizeof(void *));
    return matrix_ptr;
}
matrix *generate_int_matrix(int string, int column)
{
    matrix *matrix_ptr = malloc(sizeof(matrix));
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