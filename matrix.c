#include "matrix.h"
#include "errors.h"

matrix *create_matrix()
{
    matrix *matrix_ptr = malloc(sizeof(matrix));
    return matrix_ptr;
}

void get_sum_matrix(matrix *matrix_one, matrix *matrix_two)
{
    if (matrix_one->count_of_line == matrix_two->count_of_line || matrix_one->count_of_column == matrix_two->count_of_column)
    {
        if (matrix_one->type_info == matrix_two->type_info)
        {
            void *element_ptr_on_first_matrix = matrix_one->element;
            void *element_ptr_on_second_matrix = matrix_two->element;
            for (int i = 1; i <= (matrix_one->count_of_column * matrix_one->count_of_line); i++)
            {

                matrix_one->type_info->sum_num(element_ptr_on_first_matrix, element_ptr_on_second_matrix, element_ptr_on_first_matrix);
                element_ptr_on_first_matrix = get_increment_element(matrix_one);
                element_ptr_on_second_matrix = get_increment_element(matrix_two);
            }
        }
        else
        {
            print_error(INCORREXT_OPERATION);
        }
    }
    else
    {
        print_error(INCORRECT_FORMAT_OF_MATRIX);
    }
}

void get_multiplication_matrix(matrix *matrix_one, matrix *matrix_two)
{
    if (matrix_one->count_of_line == matrix_two->count_of_line || matrix_one->count_of_column == matrix_two->count_of_column)
    {
        if (matrix_one->type_info == matrix_two->type_info)
        {
            void *first_element_ptr = NULL;
            void *second_element_ptr = NULL;
            for (int i = 1; i <= (matrix_one->count_of_column * matrix_two->count_of_line); i++)
            {
                first_element_ptr = matrix_one->element;
                second_element_ptr = matrix_two->element;
                matrix_one->type_info->multiplication_num(first_element_ptr, second_element_ptr, first_element_ptr);
                first_element_ptr = get_increment_element(matrix_one);
                second_element_ptr = get_increment_element(matrix_two);
            }
        }
        else
        {
            print_error(INCORREXT_OPERATION);
        }
    }
    else
    {
        print_error(INCORRECT_FORMAT_OF_MATRIX);
    }
}

void *get_needed_element(int line_index, int column_index, matrix *matrix)
{
    void *needed_elemnt_ptr = NULL;
    for (int i = 1; i <= (line_index); i++)
    {
        for (int j = 1; j <= (column_index); j++)
        {
            needed_elemnt_ptr = get_increment_element(matrix);
        }
    }
    return needed_elemnt_ptr;
}
//
void *get_increment_element(matrix *matrix)
{
    void *element_ptr = NULL;
    element_ptr = matrix->element;
    element_ptr++;
    return element_ptr;
}

void *get_decrement_element(void *element_ptr)
{
    void *new_element_ptr = NULL;
    new_element_ptr = element_ptr;
    new_element_ptr--;
    return new_element_ptr;
}

void print_matrix(matrix *matrix)
{
    void *element_ptr = matrix->element;
    for (int i = 1; i <= (matrix->count_of_column * matrix->count_of_line); i++)
    {
        matrix->type_info->print_num(element_ptr);
        element_ptr = get_increment_element(matrix);
    }
}

void transport_matrix(matrix *matrix)
{
    if (matrix != NULL)
    {
        void *element_ptr = NULL;
        void *element_ptr_for_transport = NULL;
        for (int j = 1; j <= (matrix->count_of_column); j++)
        {
            for (int i = 1; i <= (matrix->count_of_line); i++)
            {
                element_ptr = get_needed_element(j, i, matrix);
                element_ptr_for_transport = get_needed_element(i, j, matrix);
                element_ptr_for_transport = element_ptr;
            }
        }
    }
    else
    {
        print_error(MATRIX_IS_NULL);
    }
}
// TODO: look at condition, you need a array of coefficients, which would multiplication on another lines
// TODO: rewrite this function too
void sum_of_lines(matrix *matrix, int num_of_string_one, int num_of_string_two, void *coefficient)
{
    if (matrix != NULL)
    {
        int size_of_el = matrix->type_info->get_size;
        void *first_line_ptr = NULL;
        void *second_line_ptr = NULL;
        if (size_of_el == 4)
        {
            for (int i = 0; i < (matrix->count_of_column); i++)
            {
                get_needed_element(num_of_string_one, i, matrix);
                first_line_ptr = matrix->element;
                second_line_ptr = matrix->element + num_of_string_two * matrix->count_of_column * size_of_el;
                first_line_ptr = get_int_sum(first_line_ptr, second_line_ptr);
                get_increment_element(matrix);
            }
        }
        else
        {
            double *first_string_ptr = (double *)matrix->element + num_of_string_one * matrix->count_of_column * size_of_el;
            double *second_string_ptr = (double *)matrix->element + num_of_string_two * matrix->count_of_column * size_of_el;
            for (int i = 0; i < (matrix->count_of_column); i++)
            {
                *first_string_ptr = *(double *)coefficient * *second_string_ptr;
                get_increment_element(matrix);
            }
        }
    }
}