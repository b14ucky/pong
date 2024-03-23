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

    this->matrix1Rows = this->matrix1.shape().first;
    this->matrix1Columns = this->matrix1.shape().second;

    this->matrix5 = Matrix({{0}});
    this->matrix5(0, 0) = 1;

    this->matrix6 = Matrix({{1, 2, 3}, {4, 5, 6}});
    this->matrix6.transpose();
}

void MatrixTest::run()
{
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

    std::cout << "Test: \"" << this->name << "\" finished!" << std::endl;
}