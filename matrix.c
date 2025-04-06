#include "matrix.h"

int scan_string(char *string, int *line, int *column)
{
    int count_of_numbers = 0;
    int *numbers_array = NULL;
    while (*string != 0)
    {
        printf("naumber_of_el:%d\n", (int)*string);
        if ((((int)*string) == 48) && (count_of_numbers == 0))
        {
            printf("number cannot sart with zero");
            return 0;
        }
        else
        {
            if (((int)*string > 47) && ((int)*string < 58))
            {
                if (numbers_array == NULL)
                {
                    count_of_numbers++;
                    numbers_array = malloc(sizeof(int));
                    numbers_array[0] = ((int)*string - 48);
                }
                else
                {
                    printf("%d\n", count_of_numbers);
                    count_of_numbers++;
                    int *new_numbers_array = calloc(count_of_numbers, sizeof(int));
                    printf("size_of_array:%d\n", sizeof(new_numbers_array));
                    for (int j = 0; j <= (count_of_numbers - 2); j++)
                    {
                        new_numbers_array[j] = numbers_array[j];
                        new_numbers_array[count_of_numbers - 1] = (int)*string - 48;
                    }
                    for (int l = 0; l <= (count_of_numbers - 1); l++)
                    {
                        printf("%d\n", new_numbers_array[l]);
                    }
                    numbers_array = new_numbers_array;
                    for (int l = 0; l <= (count_of_numbers - 1); l++)
                    {
                        printf("%d\n", numbers_array[l]);
                    }
                }
            }
        }
        string++;
    }
    if (count_of_numbers % 2 == 0)
    {
        for (int k = 0; k <= (count_of_numbers / 2 - 1); k++)
        {
            *line = *line * 10;
            *column = *column * 10;
            *line += numbers_array[k];
            *column += numbers_array[k + (count_of_numbers / 2)];
            printf("%d\n", *line);
            printf("%d\n", *column);
        }
        if (line == column)
        {
            printf("%d\n", *line);
            printf("%d\n", *column);
        }
        else
        {
            return 0;
        }
    }
}

matrix *create_matrix(int string, int column)
{
    matrix *matrix_ptr = malloc(sizeof(matrix));
    matrix_ptr->count_of_line = string;
    matrix_ptr->count_of_column = column;
    matrix_ptr->element = malloc(string * column * sizeof(void *));
}
matrix *generate_matrix(int string, int column)
{
    matrix *matrix_ptr = malloc(sizeof(matrix));
    matrix_ptr->count_of_line = string;
    matrix_ptr->count_of_column = column;
    matrix_ptr->element = malloc(string * column * sizeof(void *));
    return matrix_ptr;
    // rand
}
void get_sum_matrix(matrix *matrix_one, matrix *matrix_two)
{
    if (matrix_one->count_of_line == matrix_two->count_of_line || matrix_one->count_of_column == matrix_two->count_of_column)
    {
        if (matrix_one->type_info == matrix_two->type_info)
        {
            for (int i = 1; i <= (matrix_one->count_of_column * matrix_one->count_of_line); i++)
            {
                matrix_one->type_info->sum_num(matrix_one->element, matrix_two->element, matrix_one->element);
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
    if (matrix_one->count_of_line == matrix_two->count_of_line || matrix_one->count_of_column == matrix_two->count_of_column)
    {
        if (matrix_one->type_info == matrix_two->type_info)
        {
            for (int i = 1; i <= (matrix_one->count_of_column * matrix_two->count_of_line); i++)
            {
                matrix_one->type_info->multiplication_num(matrix_one->element, matrix_two->element, matrix_one->element);
                get_increment_element(matrix_one);
                get_increment_element(matrix_two);
            }
        }
    }
    else
    {
        printf("incorrect format of matrix");
    }
}
void *get_needed_el(int string_index, int column_index, matrix *matrix)
{
    void *needed_elemnt_ptr = NULL;
    for (int i = 1; i <= (string_index * column_index); i++)
    {
        needed_elemnt_ptr = get_increment_element(matrix);
    }
    return needed_elemnt_ptr;
}
void *get_increment_el(matrix *matrix)
{
    void *element_ptr = NULL;
    element_ptr = matrix->element;
    element_ptr++;
    return element_ptr;
}
void print_matrix(matrix *matrix)
{
    for (int i = 1; (matrix->count_of_column * matrix->count_of_line); i++)
    {
        if (matrix->type_info->get_size == 4)
        {
            printf("%d", *(int *)matrix->element);
            get_increment_el(matrix);
        }
        if (matrix->type_info->get_size == 8)
        {
            printf("%.2f", *(double *)matrix->element);
            get_increment_el(matrix);
        }
    }
}

void transport_matrix(matrix *matrix)
{
    if (matrix != NULL)
    {
        int size_of_el = matrix->type_info->get_size;
        void *element_ptr = NULL;
        for (int j = 0; j < (matrix->count_of_column); j++)
        {
            for (int i = 0; i < (matrix->count_of_line); i++)
            {
                element_ptr = get_needed_element(j, i, matrix);
            }
        }
    }
}

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
                get_needed_el(num_of_string_one, i, matrix);
                first_line_ptr = matrix->element;
                second_line_ptr = matrix->element + num_of_string_two * matrix->count_of_column * size_of_el;
                first_line_ptr = get_int_sum(first_line_ptr, second_line_ptr);
                get_increment_el(matrix);
            }
        }
        else
        {
            double *first_string_ptr = (double *)matrix->element + num_of_string_one * matrix->count_of_column * size_of_el;
            double *second_string_ptr = (double *)matrix->element + num_of_string_two * matrix->count_of_column * size_of_el;
            for (int i = 0; i < (matrix->count_of_column); i++)
            {
                *first_string_ptr = *(double *)coefficient * *second_string_ptr;
                get_increment_el(matrix);
            }
        }
    }
}