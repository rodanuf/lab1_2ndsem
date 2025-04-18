#include "../headers/matrix.h"
#include "../headers/errors.h"

matrix *create_matrix()
{
    matrix *matrix_p = malloc(sizeof(matrix));
    return matrix_p;
}

void get_sum_matrix(matrix *matrix1, matrix *matrix2, matrix *m_result)
{
    print_error(check_matrices_same(matrix1, matrix2));
    print_error(check_matrix_null(matrix1));
    void *p_on_1st_element = matrix1->element;
    void *p_on_2nd_element = matrix2->element;
    void *p_on_result = m_result->element;
    for (int i = 1; i <= (matrix1->columns * matrix1->lines); i++)
    {
        matrix1->type_info->sum(p_on_1st_element, p_on_2nd_element, p_on_result);
        p_on_1st_element = get_increment_element(matrix1, p_on_1st_element);
        p_on_2nd_element = get_increment_element(matrix2, p_on_2nd_element);
        p_on_result = get_increment_element(m_result, p_on_result);
    }
}

void get_multiplication_matrix(matrix *matrix1, matrix *matrix2, matrix *m_result)
{
    print_error(check_matrices_same(matrix1, matrix2));
    print_error(check_matrix_null(matrix1));
    void *p_on_1st_element = matrix1->element;
    void *p_on_2nd_element = matrix2->element;
    void *p_on_result = m_result->element;
    void *p_enterim = malloc(matrix1->type_info->get_size());
    for (int i = 1; i <= (matrix2->lines); i++)
    {
        for (int k = 1; k <= (matrix1->columns); k++)
        {
            for (int j = 1; j <= (matrix2->columns); j++)
            {
                p_on_1st_element = get_needed_element(i, j, matrix1);
                p_on_2nd_element = get_needed_element(j, k, matrix2);
                matrix2->type_info->multiplication(p_on_1st_element, p_on_2nd_element, p_enterim);
                matrix1->type_info->sum(p_enterim, p_on_result, p_on_result);
            }
            p_on_result = get_increment_element(m_result, p_on_result);
        }
    }
}

void *get_needed_element(int line_index, int column_index, matrix *matrix)
{
    void *needed_elemnt_p = matrix->element;
    for (int i = 1; i <= ((line_index - 1) * matrix->columns + (column_index - 1)); i++)
    {
        needed_elemnt_p = get_increment_element(matrix, needed_elemnt_p);
    }
    return needed_elemnt_p;
}
//
void *get_increment_element(matrix *matrix, void *ptr_element)
{
    char *new_elemnt_ptr = (char *)ptr_element;
    new_elemnt_ptr += matrix->type_info->get_size();
    return (void *)new_elemnt_ptr;
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
            printf(" ");
            matrix->type_info->print((void *)element_ptr);
            element_ptr += matrix->type_info->get_size();
        }
        printf("\n");
    }
}

void transpose_matrix(matrix *m_originaly, matrix *m_result)
{
    check_matrix_null(m_originaly);
    void *p_on_1st_element = m_originaly->element;
    void *p_on_result = m_result->element;
    for (int j = 1; j <= (m_originaly->lines); j++)
    {
        for (int i = 1; i <= (m_originaly->columns); i++)
        {
            p_on_1st_element = get_needed_element(i, j, m_originaly);
            m_originaly->type_info->swap(p_on_1st_element, p_on_result);
            p_on_result = get_increment_element(m_result, p_on_result);
        }
    }
}

void write_array_matrix(matrix *matrix, void *p_array)
{
    print_error(check_matrix_null(matrix));
    print_error(check_data_matrix_null(matrix));
    matrix->element = p_array;
}

void linear_combination_of_lines(matrix *matrix, int index, void *p_array)
{
    print_error(check_matrix_null(matrix));
    print_error(check_data_matrix_null(matrix));
    void *p_on_element = matrix->element;
    void *p_on_2nd_element = p_array;
    for (int i = 1; i <= (matrix->lines); i++)
    {
        for (int j = 1; j <= (matrix->columns); j++)
        {
            matrix->type_info->multiplication(p_on_element, p_on_2nd_element, p_on_element);
            p_on_element = get_increment_element(matrix, p_on_element);
        }
        p_on_2nd_element = get_increment_element(matrix, p_on_2nd_element);
    }
    void *p_on_index_line;
    for (int i = 1; i <= (matrix->lines); i++)
    {
        if (i == index)
        {
            continue;
        }
        for (int j = 1; j <= (matrix->columns); j++)
        {
            p_on_index_line = get_needed_element(index, j, matrix);
            p_on_element = get_needed_element(i, j, matrix);
            matrix->type_info->sum(p_on_index_line, p_on_element, p_on_index_line);
        }
    }
}