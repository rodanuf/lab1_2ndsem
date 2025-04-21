#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "type_info.h"
// TODO: never use malloc and other dynamic memory allocation in cicles
// TODO: use "rename symbol" (f2) to rename all defenitions of this object
// TODO: отступы должны быть в одну строку, если хочется как-то разграничить - используй комментарии
// TODO: операция не должна изменять операнд (при возможности)
// TODO: пробелы между скобками ставить нужно, но осознанно
// TODO: более приоритетные операции сжимаем, а всякие + или - оставляем с пробелами
// TODO: тесты с автомотическими объектами
// TODO: освобождает выделеную память тот кто её выделяет, а не всегда функции, реализующие абстрактный тип
// TODO: ошибки проверять в controller
// TODO: check all functions in tests
typedef struct matrix
{
    void *element;
    int rows;
    int columns;
    const struct type_info *type_info;
} matrix;

matrix *create_matrix();
void sum_matrix(matrix *matrix1, matrix *matrix2, matrix *m_result);
void multiply_matrix(matrix *matrix1, matrix *matrix2, matrix *m_result);
void *get_element(int row_index, int column_index, matrix *matrix);
void print_matrix(matrix *matrix);
void transpose_matrix(matrix *matrix);
void write_array_into_matrix(matrix *matrix, void *array);
void linear_combination_of_lines(matrix *matrix, int target_row, void *coefficients); 