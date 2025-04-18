#include <stdio.h>
#include <stdlib.h>
#include "../headers/matrix.h"
#include "../headers/controller.h"

int main()
{
    printf("please, choose a matrix operation:\n\t");
    printf("1. sum matrices\n\t");
    printf("2. multplication matrices\n\t");
    printf("3. transposition of matrix\n\t");
    printf("4. linear combination of rows\n");
    int starting_choice;
    scanf("%i", &starting_choice);
    multiple_choice(starting_choice);
}