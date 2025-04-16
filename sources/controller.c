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

        char matrix_size[80];
        char choiced_type[30];
        int line = 0;
        int column = 0;
        printf("size of matrix (string and column)\n\t");
        fgets(matrix_size, sizeof(matrix_size), stdin);
        scanf("%79[^\n]", matrix_size);
        scan_string(matrix_size, &line, &column);
        printf("matrix_size:%d\n", line * column);
        matrix *matrix = create_matrix(line, column);
        printf("what type of matrix you need?\n");
        scanf("%s", &choiced_type);
        giving_data_type_to_matrix(matrix, choiced_type);
        printf("please, write a value to you matrix\n");
        write_value_into_matrix(matrix);
        break;
    }
    return 0;
}
void giving_data_type_to_matrix(matrix *matrix, char *choiced_type)
{
    if (strcmp(choiced_type, "double") == 0)
    {
        matrix->type_info = get_double_type(matrix);
    }
    if (strcmp(choiced_type, "integer") == 0)
    {
        matrix->type_info = get_int_type(matrix);
    }
}

void write_value_into_matrix(matrix *matrix)
{
    void *element_ptr = NULL;
    element_ptr = matrix->element;
    if (is_correct_type(matrix))
    {
        for (int i = 1; i <= (matrix->lines * matrix->columns); i++)
        {
            matrix->type_info->read(element_ptr);
            element_ptr = get_increment_element(matrix);
        }
    }
}
