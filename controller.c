#include "controller.h"
#include "type_info.h"

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
        printf("matrix_size:%d", line * column);
        matrix *matrix = create_matrix(line, column);
        printf("what type of matrix you need?\n");
        printf("double/integer?\n");
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
        matrix->type_info = get_type_double(matrix);
    }
    if (strcmp(choiced_type, "integer") == 0)
    {
        matrix->type_info = get_type_integer(matrix);
    }
}

void write_value_into_matrix(matrix *matrix)
{
    void *element_ptr = NULL;
    element_ptr = matrix->element;
    for (int i = 1; i <= (matrix->count_of_line * matrix->count_of_column); i++)
    {
        matrix->type_info->write_num(element_ptr);
        element_ptr = get_increment_element(matrix);
    }
}
