#include "MatrixTest.h"

MatrixTest::MatrixTest()
{
    this->name = "MatrixTest";
}

void MatrixTest::setup()
{
    /*
        Function to set up the test objects etc.
    */
    // test multiplication, multiplication by scalar and different constructors
    this->matrix1 = Matrix(2, 2);
    this->matrix2 = Matrix(2, 2);
    this->matrix3 = Matrix({{0, 0}, {0, 0}});

    this->matrix1(0, 0) = 1;
    this->matrix1(0, 1) = 2;
    this->matrix1(1, 0) = 3;
    this->matrix1(1, 1) = 4;

    this->matrix2 = {{1, 2}, {3, 4}};

    this->matrix3 = this->matrix1 * this->matrix2;

    this->matrix4 = this->matrix1 * 2;

    // test shape method
    this->matrix1Rows = this->matrix1.shape().first;
    this->matrix1Columns = this->matrix1.shape().second;

    // test assignment operator
    this->matrix5 = Matrix({{0}});
    this->matrix5(0, 0) = 1;

    // test transpose
    this->matrix6 = Matrix({{1, 2, 3}, {4, 5, 6}});
    this->matrix6.transpose();

    // test division by scalar
    this->matrix7 = Matrix({{5, 5}, {5, 5}});
    this->matrix7 = this->matrix7 / 5;

    // test addition
    this->matrix8 = Matrix({{1, 1}, {1, 1}});
    this->matrix8 = this->matrix8 + this->matrix7;

    // test substraction
    this->matrix9 = Matrix({{1, 1}, {1, 1}});
    this->matrix9 = this->matrix9 - this->matrix7;

    // test scalar addition
    this->matrix10 = Matrix({{1, 2}, {3, 4}});
    this->matrix10 = this->matrix10 + 1;

    // test scalar substraction
    this->matrix11 = Matrix({{1, 1}, {1, 1}});
    this->matrix11 = this->matrix11 - 1;
}

void MatrixTest::run()
{
    /*
        Function to run the tests.
    */
    std::cout << "Running test: \"" << this->name << "\"" << std::endl;

    ASSERT_EQUALS(this->matrix3(0, 0), 7);
    ASSERT_EQUALS(this->matrix3(0, 1), 10);
    ASSERT_EQUALS(this->matrix3(1, 0), 15);
    ASSERT_EQUALS(this->matrix3(1, 1), 22);
    ASSERT_EQUALS(this->matrix4(0, 0), 2);
    ASSERT_EQUALS(this->matrix4(0, 1), 4);
    ASSERT_EQUALS(this->matrix4(1, 0), 6);
    ASSERT_EQUALS(this->matrix4(1, 1), 8);
    ASSERT_EQUALS(this->matrix1Rows, 2);
    ASSERT_EQUALS(this->matrix1Columns, 2);
    ASSERT_EQUALS(this->matrix5(0, 0), 1);
    ASSERT_EQUALS(this->matrix6(0, 0), 1);
    ASSERT_EQUALS(this->matrix6(0, 1), 4);
    ASSERT_EQUALS(this->matrix6(1, 0), 2);
    ASSERT_EQUALS(this->matrix6(1, 1), 5);
    ASSERT_EQUALS(this->matrix6(2, 0), 3);
    ASSERT_EQUALS(this->matrix6(2, 1), 6);
    ASSERT_EQUALS(this->matrix7(0, 0), 1);
    ASSERT_EQUALS(this->matrix7(0, 1), 1);
    ASSERT_EQUALS(this->matrix7(1, 0), 1);
    ASSERT_EQUALS(this->matrix7(1, 1), 1);
    ASSERT_EQUALS(this->matrix8(0, 0), 2);
    ASSERT_EQUALS(this->matrix8(0, 1), 2);
    ASSERT_EQUALS(this->matrix8(1, 0), 2);
    ASSERT_EQUALS(this->matrix8(1, 1), 2);
    ASSERT_EQUALS(this->matrix9(0, 0), 0);
    ASSERT_EQUALS(this->matrix9(0, 1), 0);
    ASSERT_EQUALS(this->matrix9(1, 0), 0);
    ASSERT_EQUALS(this->matrix9(1, 1), 0);
    ASSERT_EQUALS(this->matrix10(0, 0), 2);
    ASSERT_EQUALS(this->matrix10(0, 1), 3);
    ASSERT_EQUALS(this->matrix10(1, 0), 4);
    ASSERT_EQUALS(this->matrix10(1, 1), 5);
    ASSERT_EQUALS(this->matrix11(0, 0), 0);
    ASSERT_EQUALS(this->matrix11(0, 1), 0);
    ASSERT_EQUALS(this->matrix11(1, 0), 0);
    ASSERT_EQUALS(this->matrix11(1, 1), 0);

    std::cout << "Test: \"" << this->name << "\" finished!" << std::endl;
}