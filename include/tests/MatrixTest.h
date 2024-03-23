#pragma once

#include "Test.h"
#include "Matrix.h"

class MatrixTest : public Test
{
private:
    Matrix matrix1;
    Matrix matrix2;
    Matrix matrix3;
    Matrix matrix4;
    int matrix1Rows;
    int matrix1Columns;
    Matrix matrix5;
    Matrix matrix6;
    Matrix matrix7;
    Matrix matrix8;
    Matrix matrix9;
    Matrix matrix10;
    Matrix matrix11;

public:
    MatrixTest();
    void setup() override;
    void run() override;
};