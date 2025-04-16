#include "../headers/controller.h"
#include "../headers/type_info.h"
#include "../headers/errors.h"

void scan_string(char *string, int *line, int *column)
{
    int count_of_numbers = 0;
    int *numbers_array = NULL;
    while (*string != 0)
    {
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
                    count_of_numbers++;
                    int *new_numbers_array = calloc(count_of_numbers, sizeof(int));
                    for (int j = 0; j <= (count_of_numbers - 2); j++)
                    {
                        new_numbers_array[j] = numbers_array[j];
                        new_numbers_array[count_of_numbers - 1] = (int)*string - 48;
                    }
                    numbers_array = new_numbers_array;
                }
            }
        }
        string++;
    }
    if (is_correct_size(count_of_numbers))
    {
        for (int k = 0; k <= (count_of_numbers / 2 - 1); k++)
        {
            *line = *line * 10;
            *column = *column * 10;
            *line += numbers_array[k];
            *column += numbers_array[k + (count_of_numbers / 2)];
        }
    }
    if (*line == *column)
    {
        printf("lines:%d\n", *line);
        printf("columns:%d\n", *column);
    }
    else
    {
        print_error(INCORRECT_FORMAT_OF_MATRIX);
    }
}

void multiple_choice(int starting_choice)
{
    switch (starting_choice)
    {
    case 1:
        printf("enter your matrices (remember, matrices must be with same types) \n");
        char matrix_size[80];
        char choiced_type[30];
        int line = 0;
        int column = 0;
        printf("size of first matrix (string and column):\n\t");
        scanf(" %79[^\n]", matrix_size);
        scan_string(matrix_size, &line, &column);
        printf("matrix_size:%d\n", line * column);
        matrix *matrix1 = create_matrix();
        printf("what type of matrix you need?\n\t");
        printf("/double/ /integer/\n");
        scanf(" %29[^\n]", choiced_type);
        giving_data_type_to_matrix(matrix1, choiced_type);
        printf("please, write a value to your matrix\n");
        write_value_into_matrix(matrix1, line, column);
        print_matrix(matrix1);
        break;
    }
    return 0;
}
void giving_data_type_to_matrix(matrix *matrix, char *choiced_type)
{
    if (is_correct_type(choiced_type))
    {
        if (strcmp(choiced_type, "double") == 0)
        {
            matrix->type_info = get_double_type();
        }
        if (strcmp(choiced_type, "integer") == 0)
        {
            matrix->type_info = get_int_type();
        }
    }
}
// вот посюда всё робит
void write_value_into_matrix(matrix *matrix, int c_lines, int n_columns)
{
    matrix->lines = c_lines;
    matrix->columns = n_columns;
    void *element_p = NULL;
    printf("enter %d elements into your matrix\n", c_lines * n_columns);
    matrix->element = malloc(matrix->type_info->get_size() * c_lines * n_columns);
    element_p = matrix->element;
    for (int i = 1; i <= (c_lines * n_columns); i++)
    {
        matrix->type_info->read(element_p);
        element_p = get_increment_element(matrix);
    }
    print_matrix(matrix);
}
