#include "../headers/controller.h"
#include "../headers/type_info.h"
#include "../headers/errors.h"

void scan_string(char *string, int *line, int *column)
{
    int i = 0;
    int num = 0;
    while ((int)string[i] != 0)
    {
        if ((int)string[i] > 48 && (int)string[i] < 58)
        {
            num = num * 10;
            num = num + (int)(string[i] - '0');
        }
        if (string[i] == '.')
        {
            break;
        }
        i++;
    }
    *line = num;
    *column = num;
}

void multiple_choice(int starting_choice)
{
    switch (starting_choice)
    {
    case 1:
        printf("default count of needed matrices for this operation is 2\n");
        matrix *matrix1 = get_consol_iteraction();
        matrix *matrix2 = get_consol_iteraction();
        matrix *m_result = create_matrix();
        template_matrix(matrix1, m_result);
        get_sum_matrix(matrix1, matrix2, m_result);
        printf("result:\n");
        printf("\n");
        print_matrix(m_result);
        free(matrix1);
        free(matrix2);
        free(m_result);
        break;
    case 2:
        printf("default count of needed matrices for this operation is 2\n");
        matrix1 = get_consol_iteraction();
        matrix2 = get_consol_iteraction();
        m_result = create_matrix();
        template_matrix(matrix1, m_result);
        get_multiplication_matrix(matrix1, matrix2, m_result);
        printf("result:\n");
        printf("\n");
        print_matrix(m_result);
        break;
    case 3:
        printf("default count of needed matrices for this operation is 1\n");
        matrix1 = get_consol_iteraction();
        transpose_matrix(matrix1);
        printf("result:\n");
        printf("\n");
        print_matrix(matrix1);
        break;
    case 4:
        printf("default count of needed matrices for this operation is 1\n");
        matrix1 = get_consol_iteraction();
        printf("enter list of coefficients:\n");
        void *p_list = read_array(matrix1);
        int index = 0;
        printf("choose index of the line to which it will be applied this operation:\n");
        scanf("%d", &index);
        linear_combination_of_lines(matrix1, index, p_list);
        printf("result:\n");
        printf("\n");
        print_matrix(matrix1);
        break;
    }
}
void giving_data_type_to_matrix(matrix *matrix, char *choiced_type)
{
    print_error(check_correct_type(choiced_type));
    if (strcmp(choiced_type, "double") == 0)
    {
        matrix->type_info = get_double_type();
    }
    if (strcmp(choiced_type, "integer") == 0)
    {
        matrix->type_info = get_int_type();
    }
}
void write_value_into_matrix(matrix *matrix, int c_lines, int n_columns)
{
    matrix->lines = c_lines;
    matrix->columns = n_columns;
    void *element_p = NULL;
    printf("enter %d elements into your matrix\n", c_lines * n_columns);
    matrix->element = malloc(matrix->type_info->get_size() * c_lines * n_columns);
    element_p = matrix->element;
    char input[100];
    for (int i = 1; i <= (c_lines * n_columns); i++)
    {

        matrix->type_info->read(element_p);
        element_p = get_increment_element(matrix, element_p);
    }
}
matrix *get_consol_iteraction()
{
    printf("enter your matrix:\n");
    printf("(remember, matrices must be with same types) \n");
    char matrix_size[80];
    char choiced_type[30];
    int line = 0;
    int column = 0;
    printf("size of matrix:\n\t");
    scanf(" %79[^\n]", matrix_size);
    scan_string(matrix_size, &line, &column);
    printf("matrix_size:%d\n", line);
    matrix *matrix = create_matrix();
    printf("what type of matrix you need?\n\t");
    printf("/double/ /integer/\n");
    scanf(" %29[^ \n]", choiced_type);
    giving_data_type_to_matrix(matrix, choiced_type);
    write_value_into_matrix(matrix, line, column);
    printf("\n");
    printf("your input matrix:\n");
    printf("\n");
    print_matrix(matrix);
    printf("\n");
    return matrix;
}

void template_matrix(matrix *matrix_sample, matrix *new_matrix)
{
    new_matrix->lines = matrix_sample->lines;
    new_matrix->columns = matrix_sample->columns;
    new_matrix->element = malloc(matrix_sample->type_info->get_size() * matrix_sample->columns * matrix_sample->lines);
    new_matrix->type_info = matrix_sample->type_info;
}
void *read_array(matrix *matrix)
{
    void *p_array = malloc(matrix->type_info->get_size() * matrix->lines);
    void *p_enterim = p_array;
    for (int i = 1; i <= matrix->lines; i++)
    {
        matrix->type_info->read(p_enterim);
        p_enterim = get_increment_element(matrix, p_enterim);
    }
    return p_array;
}