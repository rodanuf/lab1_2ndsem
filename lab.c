#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// #include "matrix.h"
// #include "functions.h"
// #include "lab.h"

int scan_string(char *string)
{
    int count_of_numbers = 0;
    int *numbers_array = NULL;
    int line = 0;
    int column = 0;
    for (int i = 0; i < sizeof(string); i++)
    {
        printf("naumber_of_el:%d\n", (int)string[i]);
        if ((((int)string[i]) == 48) && (count_of_numbers == 0))
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
                    numbers_array[0] = ((int)string[i] - 48);
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
                    }
                    new_numbers_array++;
                    *new_numbers_array = (int)*string - 48;
                    numbers_array = new_numbers_array;
                    for (int l = 0; l <= (count_of_numbers - 1); l++)
                    {
                        printf("%d\n", *numbers_array);
                        numbers_array++;
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
            line = line * 10;
            column = column * 10;
            line += numbers_array[k];
            column += numbers_array[k + (count_of_numbers / 2)];
            printf("%d\n", line);
            printf("%d\n", column);
        }
        if (line == column)
        {
            printf("%d\n", &string);
            printf("%d\n", &column);
        }
        else
        {
            return 0;
        }
    }
}

int main()
{
    printf("enter what yu want:\n\t");
    printf("enter matrix - 1\n\t");
    printf("generate random matrix - 2\n\t");
    printf("read matrix from smth - 3\n");
    int starting_choice;
    scanf("%i", &starting_choice);
    switch (starting_choice)
    {
    case 1:
        char matrix_size[80];
        int string = 0;
        int column = 0;
        printf("size of matrix (string and column)\n\t");
        fgets(matrix_size, sizeof(matrix_size), stdin);
        scanf("%79[^\n]", matrix_size);
        scan_string(matrix_size);
        printf("matrix_size:%d", string * column);
        break;
    }
    return 0;
}
