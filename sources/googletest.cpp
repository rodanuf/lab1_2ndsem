#include <gtest/gtest.h>
#include <iostream>
#include <string.h>
#include <cmath>

extern "C"
{
#include "../headers/matrix.h"
#include "../headers/controller.h"
#include "../headers/type_info.h"
#include "../headers/type_double.h"
#include "../headers/type_int.h"
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
        result_info = create_result_info();

        int_matrix1->type_info = get_int_type();
        int_matrix2->type_info = get_int_type();

        double_matrix1->type_info = get_double_type();
        double_matrix2->type_info = get_double_type();
    }

    void TearDown() override
    {
        free(int_matrix1);
        free(int_matrix2);
        free(double_matrix1);
        free(double_matrix2);
        free(result_info);
    }

    matrix *int_matrix1;
    matrix *int_matrix2;
    matrix *double_matrix1;
    matrix *double_matrix2;
    result_info *result_info;
};

TEST_F(MatrixTest, CreateMatrix)
{
    matrix *m = create_matrix();
    ASSERT_NE(m, nullptr);
    free(m);
}

TEST_F(MatrixTest, TypeAssignment)
{
    ASSERT_EQ(int_matrix1->type_info, get_int_type());
    ASSERT_EQ(double_matrix1->type_info, get_double_type());
}

TEST_F(MatrixTest, IntMatrixOperations)
{
    int_matrix1->rows = 2;
    int_matrix1->columns = 2;
    int_matrix2->rows = 2;
    int_matrix2->columns = 2;

    int elements1[4] = {1, 2, 3, 4};
    int elements2[4] = {5, 6, 7, 8};

    int_matrix1->element = malloc(get_int_type()->get_size() * 4);
    int_matrix2->element = malloc(get_int_type()->get_size() * 4);
    memcpy(int_matrix1->element, elements1, get_int_type()->get_size() * 4);
    memcpy(int_matrix2->element, elements2, get_int_type()->get_size() * 4);

    matrix *sum_result = create_matrix();
    template_matrix(int_matrix1, sum_result);
    sum_matrix(int_matrix1, int_matrix2, sum_result);

    ASSERT_EQ(*(int *)get_element(1, 1, sum_result), 6);
    ASSERT_EQ(*(int *)get_element(1, 2, sum_result), 8);
    ASSERT_EQ(*(int *)get_element(2, 1, sum_result), 10);
    ASSERT_EQ(*(int *)get_element(2, 2, sum_result), 12);

    matrix *mult_result = create_matrix();
    template_matrix(int_matrix1, mult_result);
    multiply_matrix(int_matrix1, int_matrix2, mult_result);

    ASSERT_EQ(*(int *)get_element(1, 1, mult_result), 19);
    ASSERT_EQ(*(int *)get_element(1, 2, mult_result), 22);
    ASSERT_EQ(*(int *)get_element(2, 1, mult_result), 43);
    ASSERT_EQ(*(int *)get_element(2, 2, mult_result), 50);

    transpose_matrix(int_matrix1);
    ASSERT_EQ(int_matrix1->rows, 2);
    ASSERT_EQ(int_matrix1->columns, 2);
    ASSERT_EQ(*(int *)get_element(1, 1, int_matrix1), 1);
    ASSERT_EQ(*(int *)get_element(1, 2, int_matrix1), 3);
    ASSERT_EQ(*(int *)get_element(2, 1, int_matrix1), 2);
    ASSERT_EQ(*(int *)get_element(2, 2, int_matrix1), 4);

    free(sum_result);
    free(mult_result);
}

TEST_F(MatrixTest, DoubleMatrixOperations)
{
    double_matrix1->rows = 2;
    double_matrix1->columns = 2;
    double_matrix2->rows = 2;
    double_matrix2->columns = 2;

    double elements1[4] = {1.1, 2.2, 3.3, 4.4};
    double elements2[4] = {5.5, 6.6, 7.7, 8.8};

    double_matrix1->element = malloc(get_double_type()->get_size() * 4);
    double_matrix2->element = malloc(get_double_type()->get_size() * 4);
    memcpy(double_matrix1->element, elements1, get_double_type()->get_size() * 4);
    memcpy(double_matrix2->element, elements2, get_double_type()->get_size() * 4);

    matrix *sum_result = create_matrix();
    template_matrix(double_matrix1, sum_result);
    sum_matrix(double_matrix1, double_matrix2, sum_result);

    ASSERT_DOUBLE_EQ(*(double *)get_element(1, 1, sum_result), 6.6);
    ASSERT_DOUBLE_EQ(*(double *)get_element(1, 2, sum_result), 8.8);
    ASSERT_DOUBLE_EQ(*(double *)get_element(2, 1, sum_result), 11.0);
    ASSERT_DOUBLE_EQ(*(double *)get_element(2, 2, sum_result), 13.2);

    matrix *mult_result = create_matrix();
    template_matrix(double_matrix1, mult_result);
    multiply_matrix(double_matrix1, double_matrix2, mult_result);

    ASSERT_NEAR(*(double *)get_element(1, 1, mult_result), 26.62, 0.001);
    ASSERT_NEAR(*(double *)get_element(1, 2, mult_result), 30.14, 0.001);
    ASSERT_NEAR(*(double *)get_element(2, 1, mult_result), 61.93, 0.001);
    ASSERT_NEAR(*(double *)get_element(2, 2, mult_result), 71.39, 0.001);

    free(sum_result);
    free(mult_result);
}

TEST_F(MatrixTest, LinearCombination)
{
    int_matrix1->rows = 3;
    int_matrix1->columns = 3;
    int elements[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int_matrix1->element = malloc(get_int_type()->get_size() * 9);
    memcpy(int_matrix1->element, elements, get_int_type()->get_size() * 9);

    int coefficients[2] = {2, 3};
    void *p_coeff = malloc(get_int_type()->get_size() * 2);
    memcpy(p_coeff, coefficients, get_int_type()->get_size() * 2);

    linear_combination_of_lines(int_matrix1, 3, p_coeff);

    ASSERT_EQ(*(int *)get_element(3, 1, int_matrix1), 1 * 2 + 4 * 3 + 7);
    ASSERT_EQ(*(int *)get_element(3, 2, int_matrix1), 2 * 2 + 5 * 3 + 8);
    ASSERT_EQ(*(int *)get_element(3, 3, int_matrix1), 3 * 2 + 6 * 3 + 9);

    free(p_coeff);
}

TEST_F(MatrixTest, ErrorHandling)
{
    type_error error;
    check_correct_size("abc", &error);
    ASSERT_EQ(error.error, INCORRECT_INPUT);

    check_correct_size("123", &error);
    ASSERT_EQ(error.error, -1);

    check_correct_type("invalid", &error);
    ASSERT_EQ(error.error, INCORRECT_TYPE);

    check_correct_type("integer", &error);
    ASSERT_EQ(error.error, -1);

    check_correct_type("double", &error);
    ASSERT_EQ(error.error, -1);

    matrix *m1 = create_matrix();
    matrix *m2 = create_matrix();
    m1->type_info = get_int_type();
    m2->type_info = get_double_type();
    m1->rows = 2;
    m1->columns = 2;
    m2->rows = 3;
    m2->columns = 3;

    check_matrices_same(m1, m2, &error);
    ASSERT_EQ(error.error, INCORRECT_OPERATION);

    free(m1);
    free(m2);
}

TEST_F(MatrixTest, MatrixPrinting)
{
    int_matrix1->rows = 2;
    int_matrix1->columns = 2;
    int elements[4] = {1, 2, 3, 4};
    int_matrix1->element = malloc(get_int_type()->get_size() * 4);
    memcpy(int_matrix1->element, elements, get_int_type()->get_size() * 4);

    testing::internal::CaptureStdout();
    print_matrix(int_matrix1);
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_TRUE(output.find("1") != std::string::npos);
    ASSERT_TRUE(output.find("2") != std::string::npos);
    ASSERT_TRUE(output.find("3") != std::string::npos);
    ASSERT_TRUE(output.find("4") != std::string::npos);
}

TEST_F(MatrixTest, NonSquareMatrixOperations)
{
    int_matrix1->rows = 2;
    int_matrix1->columns = 3;
    int_matrix2->rows = 3;
    int_matrix2->columns = 2;

    int elements1[6] = {1, 2, 3, 4, 5, 6};
    int elements2[6] = {7, 8, 9, 10, 11, 12};

    int_matrix1->element = malloc(get_int_type()->get_size() * 6);
    int_matrix2->element = malloc(get_int_type()->get_size() * 6);
    memcpy(int_matrix1->element, elements1, get_int_type()->get_size() * 6);
    memcpy(int_matrix2->element, elements2, get_int_type()->get_size() * 6);

    matrix *mult_result = create_matrix();
    mult_result->rows = 2;
    mult_result->columns = 2;
    mult_result->element = calloc(4, get_int_type()->get_size());
    mult_result->type_info = get_int_type();

    multiply_matrix(int_matrix1, int_matrix2, mult_result);

    ASSERT_EQ(*(int *)get_element(1, 1, mult_result), 58);
    ASSERT_EQ(*(int *)get_element(1, 2, mult_result), 64);
    ASSERT_EQ(*(int *)get_element(2, 1, mult_result), 139);
    ASSERT_EQ(*(int *)get_element(2, 2, mult_result), 154);

    transpose_matrix(int_matrix1);
    ASSERT_EQ(int_matrix1->rows, 3);
    ASSERT_EQ(int_matrix1->columns, 2);
    ASSERT_EQ(*(int *)get_element(1, 1, int_matrix1), 1);
    ASSERT_EQ(*(int *)get_element(1, 2, int_matrix1), 4);
    ASSERT_EQ(*(int *)get_element(2, 1, int_matrix1), 2);
    ASSERT_EQ(*(int *)get_element(2, 2, int_matrix1), 5);
    ASSERT_EQ(*(int *)get_element(3, 1, int_matrix1), 3);
    ASSERT_EQ(*(int *)get_element(3, 2, int_matrix1), 6);

    free(mult_result);
}

TEST_F(MatrixTest, InputValidation)
{
    char size_input[80] = "3x3";
    int line, column;
    scan_size(size_input, &line, &column, result_info);
    ASSERT_NE(result_info->error_handing->error, -1);

    strcpy(size_input, "3");
    scan_size(size_input, &line, &column, result_info);
    ASSERT_EQ(result_info->error_handing->error, -1);
    ASSERT_EQ(line, 3);
    ASSERT_EQ(column, 3);

    char type_input[30] = "invalid";
    check_correct_type(type_input, result_info->error_handing);
    ASSERT_NE(result_info->error_handing->error, -1);

    strcpy(type_input, "integer");
    check_correct_type(type_input, result_info->error_handing);
    ASSERT_EQ(result_info->error_handing->error, -1);
}

TEST(ExitTest, CheckExitCommand)
{
    char input[10] = "exit";
    testing::internal::CaptureStdout();
    EXPECT_EXIT(check_exit(input), ::testing::ExitedWithCode(1), "");
    std::string output = testing::internal::GetCapturedStdout();
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}