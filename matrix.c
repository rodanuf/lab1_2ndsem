#include "matrix.h"
#include "errors.h"

// TODO: move this function also into controller
int scan_string(char *string, int *line, int *column)
{
    int count_of_numbers = 0;
    int *numbers_array = NULL;
    while (*string != 0)
    {
        printf("naumber_of_el:%d\n", (int)*string);
        if ((((int)*string) == 48) && (count_of_numbers == 0))
        {
            printf("number cannot sart with zero\n");
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

matrix *create_matrix(int count_of_line, int count_of_column)
{
    matrix *matrix_ptr = malloc(sizeof(matrix));
    matrix_ptr->count_of_line = count_of_line;
    matrix_ptr->count_of_column = count_of_column;
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
                get_increment_element(matrix_two);
            }
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
// TODO: rewrite this function (what if we need in a21 elment?)
void *get_needed_element(int line_index, int column_index, matrix *matrix)
{
    void *needed_elemnt_ptr = NULL;
    for (int i = 1; i <= (line_index); i++)
    {
        for (int j = 1; j <= (column_index); j++)
        {
            if (i == line_index && j == column_index)
            {
                return needed_elemnt_ptr;
            }
            else
            {
                needed_elemnt_ptr = get_increment_element(matrix);
            }
        }
    }
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
// TODO: move this function into controller
// TODO: maybe write a this function in type_info?
void print_matrix(matrix *matrix)
{
    void *element_ptr = matrix->element;
    for (int i = 1; i <= (matrix->count_of_column * matrix->count_of_line); i++)
    {
        printf("%p", *)
    }
}

void transport_matrix(matrix *matrix)
{
    if (matrix != NULL)
    {
        int size_of_el = matrix->type_info->get_size;
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