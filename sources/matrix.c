#include "../headers/matrix.h"
#include "../headers/errors.h"

matrix *create_matrix()
{
    matrix *matrix_p = malloc(sizeof(matrix));
    return matrix_p;
}

void sum_matrix(matrix *matrix1, matrix *matrix2, matrix *m_result)
{
    void *p_on_1st_element = matrix1->element;
    void *p_on_2nd_element = matrix2->element;
    void *p_on_result = m_result->element;
    for (int i = 1; i <= (matrix1->columns * matrix1->rows); i++)
    {
        matrix1->type_info->sum(p_on_1st_element, p_on_2nd_element, p_on_result);
        p_on_1st_element += matrix1->type_info->get_size();
        p_on_2nd_element += matrix2->type_info->get_size();
        p_on_result += m_result->type_info->get_size();
    }
}

void multiply_matrix(matrix *matrix1, matrix *matrix2, matrix *m_result)
{
    void *p_on_1st_element = matrix1->element;
    void *p_on_2nd_element = matrix2->element;
    void *p_on_result = m_result->element;
    void *p_enterim = malloc(matrix1->type_info->get_size());
    for (int i = 1; i <= (matrix2->rows); i++)
    {
        for (int k = 1; k <= (matrix1->columns); k++)
        {
            for (int j = 1; j <= (matrix2->columns); j++)
            {
                p_on_1st_element = get_element(i, j, matrix1);
                p_on_2nd_element = get_element(j, k, matrix2);
                matrix2->type_info->multiplication(p_on_1st_element, p_on_2nd_element, p_enterim);
                matrix1->type_info->sum(p_enterim, p_on_result, p_on_result);
            }
            p_on_result += matrix1->type_info->get_size();
        }
    }
    free(p_enterim);
}

void *get_element(int line_index, int column_index, matrix *matrix)
{
    void *needed_elemnt_p = matrix->element;
    needed_elemnt_p += matrix->type_info->get_size() * (line_index - 1) * matrix->columns + matrix->type_info->get_size() * (column_index - 1);
    return needed_elemnt_p;
}

void print_matrix(matrix *matrix)
{
    char *element_ptr = (char *)matrix->element;
    for (int i = 0; i < (matrix->rows); i++)
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

void transpose_matrix(matrix *matrix)
{
    void *p_on_line = matrix->element;
    void *p_on_column = matrix->element;
    for (int j = 1; j <= (matrix->rows); j++)
    {
        for (int i = j; i <= (matrix->columns); i++)
        {
            if (i == j)
            {
                continue;
            }
            p_on_line = get_element(j, i, matrix);
            p_on_column = get_element(i, j, matrix);
            matrix->type_info->swap(p_on_column, p_on_line);
        }
    }
}

void write_array_into_matrix(matrix *matrix, void *array)
{
    matrix->element = array;
}

void linear_combination_of_lines(matrix *matrix, int target_line, void *p_array)
{
    void *p_on_element = matrix->element;
    void *p_on_2nd_element = p_array;
    void *enterim_row = calloc(matrix->columns, matrix->type_info->get_size());
    void *p_on_index_line = NULL;
    for (int i = 1; i <= (matrix->rows); i++)
    {
        for (int j = 1; j <= (matrix->columns); j++)
        {
            if (i == target_line)
            {
                continue;
            }
            p_on_element = get_element(i, j, matrix);
            matrix->type_info->multiplication(p_on_element, p_on_2nd_element, enterim_row);
            p_on_index_line = get_element(target_line, j, matrix);
            matrix->type_info->sum(enterim_row, p_on_index_line, p_on_index_line);
            p_on_element += matrix->type_info->get_size();
            enterim_row += matrix->type_info->get_size();
            printf("%d ", *(int *)p_on_index_line);
        }
        p_on_2nd_element += matrix->type_info->get_size();
    }
    free(enterim_row);
}