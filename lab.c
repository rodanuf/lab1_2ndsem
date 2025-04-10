#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"

int main()
{
    printf("enter what you want:\n\t");
    printf("enter matrix - 1\n\t");
    printf("generate random matrix - 2\n\t");
    printf("read matrix from smth - 3\n");
    int starting_choice;
    scanf("%i", &starting_choice);
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
        printf("what type of matrix you need?\n");
        printf("double/integer?\n");
        scanf("%s", &choiced_type);
        // TODO: move this function into controllerr
        if (strcmp(choiced_type, "double") == 0)
        {
            matrix *first_matrix = create_matrix();
            first_matrix->type_info = get_type_double(first_matrix);
        }
        break;
    }
    return 0;
}
