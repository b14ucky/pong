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

public:
    MatrixTest();
    void setup() override;
    void run() override;
};