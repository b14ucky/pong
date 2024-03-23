#pragma once

#include <iostream>
#include <utility>

class Matrix
{
private:
    // number of rows and columns in the matrix
    int rows;
    int columns;
    float **data;

public:
    // constructors/destructor
    Matrix();
    Matrix(int rows, int columns);
    Matrix(std::initializer_list<std::initializer_list<float>> values);
    ~Matrix();

    // methods
    std::pair<int, int> shape() const;
    float &operator()(int row, int column);
    const float &operator()(int row, int column) const;
    Matrix operator*(const Matrix &other) const;
    Matrix operator*(float scalar);
    void operator=(const Matrix &other);
    void operator=(std::initializer_list<std::initializer_list<float>> values);
    void transpose();
    void print() const;
};