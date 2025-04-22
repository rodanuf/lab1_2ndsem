#include <gtest/gtest.h>
#include <iostream>
#include <string.h>

extern "C"
{
#include "../headers/matrix.h"
#include "../headers/controller.h"
#include "../headers/type_info.h"
#include "../headers/type_double.h"
#include "../headers/type_int.h"
#include "../headers/type_double_functions.h"
#include "../headers/type_int_functions.h"
#include "../headers/errors.h"
}

class MatrixTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        int_matrix1 = create_matrix();
        int_matrix2 = create_matrix();
        double_matrix1 = create_matrix();
        double_matrix2 = create_matrix();

        giving_data_type_to_matrix(int_matrix1, "integer");
        giving_data_type_to_matrix(int_matrix2, "integer");
        giving_data_type_to_matrix(double_matrix1, "double");
        giving_data_type_to_matrix(double_matrix2, "double");
    }

    void TearDown() override
    {
        free(int_matrix1);
        free(int_matrix2);
        free(double_matrix1);
        free(double_matrix2);
    }

    matrix *int_matrix1;
    matrix *int_matrix2;
    matrix *double_matrix1;
    matrix *double_matrix2;
};

TEST_F(MatrixTest, CreateMatrix)
{
    matrix *m = create_matrix();
    ASSERT_NE(m, nullptr);
    free(m);
}

TEST_F(MatrixTest, GivingDataType)
{
    matrix *m = create_matrix();
    giving_data_type_to_matrix(m, "integer");
    ASSERT_EQ(m->type_info, get_int_type());

    giving_data_type_to_matrix(m, "double");
    ASSERT_EQ(m->type_info, get_double_type());
    free(m);
}

TEST_F(MatrixTest, WriteValueIntoMatrix)
{
    int_matrix1->rows = 2;
    int_matrix1->columns = 2;
    int elements[4] = {1, 2, 3, 4};
    int_matrix1->element = malloc(get_size_int_element() * 4);
    memcpy(int_matrix1->element, elements, get_size_int_element() * 4);

    ASSERT_EQ(*(int *)get_element(1, 1, int_matrix1), 1);
    ASSERT_EQ(*(int *)get_element(1, 2, int_matrix1), 2);
    ASSERT_EQ(*(int *)get_element(2, 1, int_matrix1), 3);
    ASSERT_EQ(*(int *)get_element(2, 2, int_matrix1), 4);
}

TEST_F(MatrixTest, IntMatrixAddition)
{
    int_matrix1->rows = 2;
    int_matrix1->columns = 2;
    int elements1[4] = {1, 2, 3, 4};
    int_matrix1->element = malloc(get_size_int_element() * 4);
    memcpy(int_matrix1->element, elements1, get_size_int_element() * 4);

    int_matrix2->rows = 2;
    int_matrix2->columns = 2;
    int elements2[4] = {5, 6, 7, 8};
    int_matrix2->element = malloc(get_size_int_element() * 4);
    memcpy(int_matrix2->element, elements2, get_size_int_element() * 4);

    matrix *result = create_matrix();
    template_matrix(int_matrix1, result);

    sum_matrix(int_matrix1, int_matrix2, result);

    ASSERT_EQ(*(int *)get_element(1, 1, result), 6);
    ASSERT_EQ(*(int *)get_element(1, 2, result), 8);
    ASSERT_EQ(*(int *)get_element(2, 1, result), 10);
    ASSERT_EQ(*(int *)get_element(2, 2, result), 12);

    free(result);
}

TEST_F(MatrixTest, IntMatrixMultiplication)
{
    int_matrix1->rows = 2;
    int_matrix1->columns = 2;
    int elements1[4] = {1, 2, 3, 4};
    int_matrix1->element = malloc(get_size_int_element() * 4);
    memcpy(int_matrix1->element, elements1, get_size_int_element() * 4);

    int_matrix2->rows = 2;
    int_matrix2->columns = 2;
    int elements2[4] = {5, 6, 7, 8};
    int_matrix2->element = malloc(get_size_int_element() * 4);
    memcpy(int_matrix2->element, elements2, get_size_int_element() * 4);

    matrix *result = create_matrix();
    template_matrix(int_matrix1, result);

    multiply_matrix(int_matrix1, int_matrix2, result);

    ASSERT_EQ(*(int *)get_element(1, 1, result), 19);
    ASSERT_EQ(*(int *)get_element(1, 2, result), 22);
    ASSERT_EQ(*(int *)get_element(2, 1, result), 43);
    ASSERT_EQ(*(int *)get_element(2, 2, result), 50);

    free(result);
}

TEST_F(MatrixTest, IntMatrixTranspose)
{
    int_matrix1->rows = 2;
    int_matrix1->columns = 3;
    int elements[6] = {1, 2, 3, 4, 5, 6};
    int_matrix1->element = malloc(get_size_int_element() * 6);
    memcpy(int_matrix1->element, elements, get_size_int_element() * 6);

    transpose_matrix(int_matrix1);

    ASSERT_EQ(int_matrix1->rows, 3);
    ASSERT_EQ(int_matrix1->columns, 2);
    ASSERT_EQ(*(int *)get_element(1, 1, int_matrix1), 1);
    ASSERT_EQ(*(int *)get_element(1, 2, int_matrix1), 4);
    ASSERT_EQ(*(int *)get_element(2, 1, int_matrix1), 2);
    ASSERT_EQ(*(int *)get_element(2, 2, int_matrix1), 5);
    ASSERT_EQ(*(int *)get_element(3, 1, int_matrix1), 3);
    ASSERT_EQ(*(int *)get_element(3, 2, int_matrix1), 6);
}

TEST_F(MatrixTest, IntMatrixLinearCombination)
{
    int_matrix1->rows = 3;
    int_matrix1->columns = 3;
    int elements[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int_matrix1->element = malloc(get_size_int_element() * 9);
    memcpy(int_matrix1->element, elements, get_size_int_element() * 9);

    int coefficients[2] = {2, 3};
    void *p_coeff = malloc(get_size_int_element() * 2);
    memcpy(p_coeff, coefficients, get_size_int_element() * 2);

    linear_combination_of_lines(int_matrix1, 3, p_coeff);

    ASSERT_EQ(*(int *)get_element(3, 1, int_matrix1), 1 * 2 + 4 * 3 + 7);
    ASSERT_EQ(*(int *)get_element(3, 2, int_matrix1), 2 * 2 + 5 * 3 + 8);
    ASSERT_EQ(*(int *)get_element(3, 3, int_matrix1), 3 * 2 + 6 * 3 + 9);

    free(p_coeff);
}

TEST_F(MatrixTest, DoubleMatrixAddition)
{
    double_matrix1->rows = 2;
    double_matrix1->columns = 2;
    double elements1[4] = {1.1, 2.2, 3.3, 4.4};
    double_matrix1->element = malloc(get_size_double_element() * 4);
    memcpy(double_matrix1->element, elements1, get_size_double_element() * 4);

    double_matrix2->rows = 2;
    double_matrix2->columns = 2;
    double elements2[4] = {5.5, 6.6, 7.7, 8.8};
    double_matrix2->element = malloc(get_size_double_element() * 4);
    memcpy(double_matrix2->element, elements2, get_size_double_element() * 4);

    matrix *result = create_matrix();
    template_matrix(double_matrix1, result);

    sum_matrix(double_matrix1, double_matrix2, result);

    ASSERT_DOUBLE_EQ(*(double *)get_element(1, 1, result), 6.6);
    ASSERT_DOUBLE_EQ(*(double *)get_element(1, 2, result), 8.8);
    ASSERT_DOUBLE_EQ(*(double *)get_element(2, 1, result), 11.0);
    ASSERT_DOUBLE_EQ(*(double *)get_element(2, 2, result), 13.2);

    free(result);
}

TEST(ErrorHandlingTest, CheckMatricesSame)
{
    matrix *m1 = create_matrix();
    matrix *m2 = create_matrix();

    giving_data_type_to_matrix(m1, "integer");
    giving_data_type_to_matrix(m2, "double");

    m1->rows = 2;
    m1->columns = 2;
    m2->rows = 3;
    m2->columns = 3;

    type_error error;
    check_matrices_same(m1, m2, &error);

    ASSERT_EQ(error.error, INCORRECT_OPERATION);
    ASSERT_STREQ(error.message, "Incorrect operation: matrices aren't same");

    free(m1);
    free(m2);
}

TEST(InputOutputTest, PrintMatrix)
{
    matrix *m = create_matrix();
    giving_data_type_to_matrix(m, "integer");

    m->rows = 2;
    m->columns = 2;
    int elements[4] = {1, 2, 3, 4};
    m->element = malloc(get_size_int_element() * 4);
    memcpy(m->element, elements, get_size_int_element() * 4);

    testing::internal::CaptureStdout();
    print_matrix(m);
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_TRUE(output.find("1") != std::string::npos);
    ASSERT_TRUE(output.find("2") != std::string::npos);
    ASSERT_TRUE(output.find("3") != std::string::npos);
    ASSERT_TRUE(output.find("4") != std::string::npos);

    free(m);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}