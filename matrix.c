#include "matrix.h"
#include "functions.h"

matrix *create_matrix(int string, int column)
{
    matrix *matrix_ptr = malloc(sizeof(matrix));
    matrix_ptr->string = string;
    matrix_ptr->column = column;
    matrix_ptr->el = malloc(string * column * sizeof(int *));
    for (int i = 1; i <= string; i++)
    {
        for (int j = 1; j <= column; j++)
        {
            matrix_ptr->el =
                matrix_ptr->el[i][j] = 0;
            matrix_ptr->float_el[i][j] = 0;
        }
    }
    return matrix_ptr;
}
matrix *get_sum_matrix(matrix *matrix_one, matrix *matrix_two)
{
    matrix *matrix_result = malloc(sizeof(matrix));
    if (matrix_one->string == matrix_two->string || matrix_one->column == matrix_two->column)
    {
        if (matrix_one->type_info == matrix_two->type_info)
        {
            for (int i = 1; i <= (matrix_one->column + matrix_one->string); i++)
            {
                matrix_one->type_info->sum_num(matrix_one->el, matrix_two->el, matrix_result->el);
                get_increment_el(matrix_one);
                get_increment_el(matrix_two);
            }
        }
    }
}
void get_increment_el(matrix *matrix)
{
    int *element_ptr = malloc(sizeof(int));
    element_ptr = (int *)matrix->el;
    element_ptr += matrix->type_info->get_size();
    matrix->el = element_ptr;
}