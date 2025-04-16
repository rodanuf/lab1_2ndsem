#include "../headers/matrix.h"

matrix *create_matrix()
{
    matrix *matrix_p = malloc(sizeof(matrix));
    return matrix_p;
}

void get_sum_matrix(matrix *matrix1, matrix *matrix2)
{
    if (is_matrixs_same(matrix1, matrix2))
    {
        void *p_on_1st_element = matrix1->element;
        void *p_on_2nd_element = matrix2->element;
        for (int i = 1; i <= (matrix1->columns * matrix1->lines); i++)
        {
            matrix1->type_info->sum(p_on_1st_element, p_on_2nd_element, p_on_1st_element);
            p_on_1st_element = get_increment_element(matrix1);
            p_on_2nd_element = get_increment_element(matrix2);
        }
    }
}

void get_multiplication_matrix(matrix *matrix1, matrix *matrix2)
{
    if (is_matrixs_same(matrix1, matrix2))
    {
        void *p_on_1st_element = NULL;
        void *p_on_2nd_element = NULL;
        for (int i = 1; i <= (matrix2->lines); i++)
        {
            for (int j = 1; j <= (matrix2->columns); j++)
            {
                p_on_1st_element = get_needed_element(i, j, matrix1);
                p_on_2nd_element = get_needed_element(j, i, matrix2);
                matrix1->type_info->multiplication(p_on_1st_element, p_on_2nd_element, p_on_1st_element);
            }
        }
    }
}

void *get_needed_element(int line_index, int column_index, matrix *matrix)
{
    void *needed_elemnt_p = NULL;
    for (int i = 1; i <= (line_index); i++)
    {
        for (int j = 1; j <= (column_index); j++)
        {
            needed_elemnt_p = get_increment_element(matrix);
        }
    }
    if (line_index == 1 && column_index == 1)
    {
        needed_elemnt_p = matrix->element;
    }
    return needed_elemnt_p;
}
//
void *get_increment_element(matrix *matrix)
{
    char *element_ptr = (char *)matrix->element;
    element_ptr += matrix->type_info->get_size();
    return (void *)element_ptr;
}

void *get_decrement_element(matrix *matrix, void *element_ptr)
{
    char *new_element_ptr = (char *)element_ptr;
    new_element_ptr = new_element_ptr - matrix->type_info->get_size();
    return (void *)new_element_ptr;
}

void print_matrix(matrix *matrix)
{
    char *element_ptr = (char *)matrix->element;
    for (int i = 0; i < (matrix->lines); i++)
    {
        for (int j = 0; j < (matrix->columns); j++)
        {
            matrix->type_info->print(element_ptr);
            element_ptr += matrix->type_info->get_size();
        }
        printf("\n");
    }
}

void transport_matrix(matrix *matrix)
{
    if (!(is_matrix_null(matrix)))
    {
        void *element_ptr = NULL;
        void *element_ptr_for_transport = NULL;
        for (int j = 1; j <= (matrix->lines); j++)
        {
            for (int i = 1; i <= (matrix->columns); i++)
            {
                element_ptr = get_needed_element(j, i, matrix);
                element_ptr_for_transport = get_needed_element(i, j, matrix);
                element_ptr_for_transport = element_ptr;
            }
        }
    }
}
void wrtie_array_matrix(matrix *matrix, void *array_p)
{
    if (!(is_matrix_null(matrix)))
    {
        if (is_data_matrix_null(matrix))
        {
            matrix->element = array_p;
        }
    }
}
// TODO: look at condition, you need a array of coefficients, which would multiplication on another lines
// TODO: rewrite this function too
void sum_of_lines(matrix *matrix, int num_line_1, int num_line_2, void *coefficient)
{
    if (matrix != NULL)
    {
        int size_element = matrix->type_info->get_size;
        void *p_on_1st_line = NULL;
        void *p_on_2nd_line = NULL;
        if (size_element == 4)
        {
            for (int i = 0; i < (matrix->columns); i++)
            {
                get_needed_element(num_line_1, i, matrix);
                p_on_1st_line = matrix->element;
                p_on_2nd_line = matrix->element + num_line_2 * matrix->columns * size_element;
                get_int_sum(p_on_1st_line, p_on_2nd_line, p_on_1st_line);
                get_increment_element(matrix);
            }
        }
        else
        {
            double *first_string_ptr = (double *)matrix->element + num_line_1 * matrix->columns * size_element;
            double *second_string_ptr = (double *)matrix->element + num_line_2 * matrix->columns * size_element;
            for (int i = 0; i < (matrix->columns); i++)
            {
                *first_string_ptr = *(double *)coefficient * *second_string_ptr;
                get_increment_element(matrix);
            }
        }
    }
}