#include "../headers/controller.h"
#include "../headers/type_info.h"
#include "../headers/errors.h"
#include "../headers/matrix.h"
#include "../headers/type_double.h"
#include "../headers/type_int.h"

void scan_size(char *string, int *line, int *column, result_info *result)
{
    check_exit(string);
    int i = 0;
    int num = 0;
    check_correct_size(string, result->error_handing);
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
    matrix *matrix1 = NULL;
    matrix *matrix2 = NULL;
    result_info *result = create_result_info();
    switch (starting_choice)
    {
    case 1:
        printf("default count of needed matrices for this operation is 2\n");
        do
        {
            matrix1 = get_consol_iteraction(result);
            matrix2 = get_consol_iteraction(result);
            check_matrices_same(matrix1, matrix2, result->error_handing);
            check_data_matrix_null(matrix1, result->error_handing);
            check_data_matrix_null(matrix2, result->error_handing);
            result->m_result = create_matrix();
            template_matrix(matrix1, result->m_result);
            sum_matrix(matrix1, matrix2, result->m_result);
            printf("result:\n");
            printf("\n");
            print_matrix(result->m_result);
            free(matrix1);
            free(matrix2);
            free(result->m_result);
            if (result->error_handing->error != -1)
            {
                printf("something went wrong, please try again\n");
                printf("error_code:%d ", result->error_handing->error);
                printf(result->error_handing->message);
                printf("\n");
            }
        } while (result->error_handing->error != -1);
        break;
    case 2:
        printf("default count of needed matrices for this operation is 2\n");
        do
        {
            matrix1 = get_consol_iteraction(result);
            matrix2 = get_consol_iteraction(result);
            check_matrices_same(matrix1, matrix2, result->error_handing);
            check_data_matrix_null(matrix1, result->error_handing);
            check_data_matrix_null(matrix2, result->error_handing);
            result->m_result = create_matrix();
            template_matrix(matrix1, result->m_result);
            multiply_matrix(matrix1, matrix2, result->m_result);
            printf("result:\n");
            printf("\n");
            print_matrix(result->m_result);
            free(matrix1);
            free(matrix2);
            free(result->m_result);
            if (result->error_handing->error != -1)
            {
                printf("something went wrong, please try again\n");
                printf("error_code:%d ", result->error_handing->error);
                printf(result->error_handing->message);
                printf("\n");
            }
        } while (result->error_handing->error != -1);
        break;
        break;
    case 3:
        do
        {
            printf("default count of needed matrices for this operation is 1\n");
            matrix1 = get_consol_iteraction(result);
            check_data_matrix_null(matrix1, result->error_handing);
            transpose_matrix(matrix1);
            printf("result:\n");
            printf("\n");
            print_matrix(matrix1);
            free(matrix1);
        } while (result->error_handing->error != -1);
        break;
    case 4:
        printf("default count of needed matrices for this operation is 1\n");
        matrix1 = get_consol_iteraction(result);
        printf("enter list of coefficients:\n");
        void *p_list = read_array(matrix1, result);
        int index = 0;
        printf("choose index of the line to which it will be applied this operation:\n");
        scanf("%d", &index);
        linear_combination_of_lines(matrix1, index, p_list);
        printf("result:\n");
        printf("\n");
        print_matrix(matrix1);
        free(matrix1);
        free(p_list);
        break;
    }
}

void giving_data_type_to_matrix(matrix *matrix, result_info *result)
{
    do
    {
        char choiced_type[30];
        printf("what type of matrix you need?\n\t");
        printf("/double/ /integer/\n");
        scanf(" %29[^ \n]", choiced_type);
        check_exit(choiced_type);
        check_correct_type(choiced_type, result->error_handing);
        if (strcmp(choiced_type, "double") == 0)
        {
            matrix->type_info = get_double_type();
        }
        if (strcmp(choiced_type, "integer") == 0)
        {
            matrix->type_info = get_int_type();
        }
        if (result->error_handing->error != -1)
        {
            printf("something went wrong, please try again\n");
            printf("error_code:%d ", result->error_handing->error);
            printf(result->error_handing->message);
            printf("\n");
        }
        memset(choiced_type, 0, sizeof(choiced_type));
    } while (result->error_handing->error != -1);
}

void write_value_into_matrix(matrix *matrix, int c_lines, int n_columns, result_info *result)
{
    matrix->rows = c_lines;
    matrix->columns = n_columns;
    void *element_p = NULL;
    printf("enter %d elements into your matrix\n", c_lines * n_columns);
    matrix->element = calloc(c_lines * n_columns, matrix->type_info->get_size());
    element_p = matrix->element;
    for (int i = 1; i <= (c_lines * n_columns); i++)
    {
        do
        {
            clean_buffer();
            matrix->type_info->read(element_p, matrix, result->error_handing);
            if (result->error_handing->error != -1)
            {
                printf("something went wrong, please try again\n");
                printf("error_code:%d ", result->error_handing->error);
                printf(result->error_handing->message);
                printf("\n");
            }
        } while (result->error_handing->error != -1);
        element_p += matrix->type_info->get_size();
    }
}

matrix *get_consol_iteraction(result_info *result)
{
    printf("enter your matrix:\n");
    printf("(remember, matrices must be with same types) \n");
    char matrix_size[80];
    int line = 0;
    int column = 0;
    do
    {
        printf("size of matrix:\n\t");
        scanf(" %79[^\n]", matrix_size);
        check_correct_size(matrix_size, result->error_handing);
        if (result->error_handing->error != -1)
        {
            printf("something went wrong, please try again\n");
            printf("error_code:%d ", result->error_handing->error);
            printf(result->error_handing->message);
            printf("\n");
            memset(matrix_size, 0, sizeof(matrix_size));
        }
    } while (result->error_handing->error != -1);
    scan_size(matrix_size, &line, &column, result);
    printf("matrix_size:%d\n", line);
    matrix *matrix = create_matrix();
    giving_data_type_to_matrix(matrix, result);
    write_value_into_matrix(matrix, line, column, result);
    printf("\n");
    printf("your input matrix:\n");
    printf("\n");
    print_matrix(matrix);
    printf("\n");
    return matrix;
}

void template_matrix(matrix *matrix_sample, matrix *m_result)
{
    m_result->rows = matrix_sample->rows;
    m_result->columns = matrix_sample->columns;
    m_result->element = calloc(matrix_sample->columns * matrix_sample->rows, matrix_sample->type_info->get_size());
    m_result->type_info = matrix_sample->type_info;
}

void *read_array(matrix *matrix, result_info *result)
{
    void *p_array = malloc(matrix->type_info->get_size() * matrix->rows);
    void *p_enterim = p_array;
    for (int i = 1; i <= matrix->rows; i++)
    {
        matrix->type_info->read(p_enterim, matrix, result->error_handing);
        p_enterim += matrix->type_info->get_size();
    }
    return p_array;
}

void clean_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (!isspace(c))
        {
            ungetc(c, stdin);
            break;
        }
    }
}

void check_exit(char *string)
{
    if (strcmp(string, "exit") == 0)
    {
        exit(1);
    }
}

result_info *create_result_info()
{
    result_info *result = malloc(sizeof(type_info));
    result->m_result = NULL;
    result->is_succses = true;
    result->error_handing = get_success_result();
    return result;
}