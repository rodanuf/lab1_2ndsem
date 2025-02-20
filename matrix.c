#include "matrix.h"
#include "functions.h"

matrix* create_matrix(int string,int column){
    matrix* matrix_ptr = malloc(sizeof(matrix));
    matrix_ptr -> string = string;
    matrix_ptr -> column = column;
    for (int i=1; i<=string;i++){
        for (int j=1; j<=column;j++){
            matrix_ptr -> int_el[i][j] = 0;
            matrix_ptr -> float_el[i][j] = 0; 
        }
    }
    return matrix_ptr; 
}
void push_int_el (int el, matrix* matrix, int string_indx, int column_indx){
    matrix -> int_el[string_indx][column_indx] = el;
}
void push_float_el (float el, matrix* matrix, int string_indx, int column_indx){
    matrix -> float_el[string_indx][column_indx] = el;
}
void del (matrix* matrix,int string_indx, int column_indx){
    matrix -> int_el[string_indx][column_indx] = 0;
}