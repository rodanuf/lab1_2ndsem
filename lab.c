#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// #include "matrix.h"
// #include "functions.h"
// #include "lab.h"

// int scan_string(char* string){
//     int count_of_numbers = 0;
//     int* numbers_array;
//     for (int i=0;(int) sizeof(string);i++){
//         if ((((int) string[i]) == 48) && (count_of_numbers == 0)){
//             printf ("number cannot sart with zero");
//             return 0;
//         }
//         if (47<((int) string[i])<58){
//             if (numbers_array == NULL){
//                 numbers_array = malloc(sizeof(1));
//                 numbers_array[0] = ((int) string[i] - 48);
//             }
//             else{
//                 if (count_of_numbers !=0){
//                     numbers_array[((int) sizeof(numbers_array))/((int) sizeof(int)) - 1] = numbers_array[((int) sizeof(numbers_array))/((int) sizeof(int)) - 1]*10 + string[i]-48;
//                 }
//                 else{
//                     int* new_numbers_array = malloc(sizeof(numbers_array))
//                     for (int j=0;(int) sizeof())
//                 }
//             }
//         }
//     }
// }
void scan_string(char *string, int *a, int *b)
{
    if (((int)sizeof(string)) % 2 == 0)
    {
        for (int i = 0; ((int)sizeof(string)) / 2; i++)
        {
            *a = (*a) * (int)pow(10, i) + (((int)string[i]) - 48);
        }
        for (int j = 0; ((int)sizeof(string)) / 2; j++)
        {
            *b = (*b) * (int)pow(10, j) + (((int)string[j + ((int)sizeof(string)) / 2]) - 48);
        }
    }
    else
    {
        printf("wrong enter\n");
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
        scanf("%", matrix_size);
        scan_string(matrix_size, &string, &column);
        printf("matrix_size:%d", string * column);
        break;
    }
    return 0;
}
