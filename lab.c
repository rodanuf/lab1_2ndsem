#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "controller.h"

int main()
{
    printf("enter what you want:\n\t");
    printf("enter matrix - 1\n\t");
    printf("generate random matrix - 2\n\t");
    printf("read matrix from smth - 3\n");
    int starting_choice;
    scanf("%i", &starting_choice);
    multiple_choice(starting_choice);
}