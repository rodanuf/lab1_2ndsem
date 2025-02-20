#include <stdio.h>
#include "matrix.h"
#include "functions.h"
int main(){
    int a=3;
    int b=5;
    matrix* matrix_1 = create_matrix(a,b);
    for (int i=1; i<=a;i++){
        for (int j=1; j<=b;j++){
            printf("%d",matrix_1 -> int_el[i][j]);
        }
        printf("\n");
    }
    printf("Hello");
    return 0;
}
