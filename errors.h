typedef enum
{
    INCORRECT_FORMAT_OF_MATRIX = 1,
    INCORRECT_INPUT = 2,
    INCORREXT_OPERATION = 3,
    MEMORY_ERROR = 4,
    MATRIX_IS_NULL = 5
} errors;

void print_error(errors error);