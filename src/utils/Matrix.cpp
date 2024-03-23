#include "Matrix.h"

// constructors/destructor

Matrix::Matrix()
{
    /*
        This default constructor initializes the matrix with 0 rows and 0 columns
    */
    this->rows = 0;
    this->columns = 0;
    this->data = nullptr;
}

Matrix::Matrix(int rows, int columns)
{
    /*
        This constructor initializes the matrix of zeros with the given number of rows and columns
    */
    this->rows = rows;
    this->columns = columns;
    this->data = new float *[this->rows];
    for (int i = 0; i < this->rows; ++i)
    {
        this->data[i] = new float[this->columns];

        for (int j = 0; j < this->columns; ++j)
        {
            this->data[i][j] = 0.0;
        }
    }
}

Matrix::Matrix(std::initializer_list<std::initializer_list<float>> values)
{
    /*
        This constructor initializes the matrix with the given values in the form of a list of lists
    */
    this->rows = values.size();
    this->columns = values.begin()->size();
    this->data = new float *[this->rows];
    int i = 0;
    for (auto row : values)
    {
        this->data[i] = new float[this->columns];
        int j = 0;
        for (auto value : row)
        {
            this->data[i][j] = value;
            j++;
        }
        i++;
    }
}

Matrix::~Matrix()
{
    /*
        The destructor is responsible for freeing the memory allocated for the matrix
    */
    if (this->data != nullptr)
    {
        for (int i = 0; i < this->rows; ++i)
        {
            delete[] this->data[i];
        }

        delete[] this->data;
    }
}

std::pair<int, int> Matrix::shape() const
{
    /*
        This method returns the shape of the matrix as a pair of integers (rows, columns)
    */
    return std::make_pair(this->rows, this->columns);
}

const float &Matrix::operator()(int row, int column) const
{
    /*
        This method is used to read the value of the matrix at the given row and column
    */
    return this->data[row][column];
}

float &Matrix::operator()(int row, int column)
{
    /*
        This method is used to modify the value of the matrix at the given row and column
    */
    return this->data[row][column];
}

Matrix Matrix::operator*(const Matrix &other) const
{
    /*
        This method multiplies the current matrix with another matrix and returns new Matrix object
        as a result of the multiplication. If the number of columns of the first matrix is not equal
        to the number of rows of the second matrix, the method throws an error.
    */
    if (this->columns != other.rows)
    {
        throw std::invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix!");
    }
    int resultRows = this->rows;
    int resultCols = other.columns;
    Matrix result(resultRows, resultCols);

    for (int i = 0; i < resultRows; ++i)
    {
        for (int j = 0; j < resultCols; ++j)
        {
            for (int k = 0; k < this->columns; ++k)
            {
                result(i, j) += data[i][k] * other(k, j);
            }
        }
    }

    return result;
}

Matrix Matrix::operator*(float scalar)
{
    /*
        This method multiplies each element of the matrix with the given scalar value.
        It return a new Matrix object with the result of the multiplication.
    */
    Matrix result(this->rows, this->columns);
    for (int i = 0; i < this->rows; ++i)
    {
        for (int j = 0; j < this->columns; ++j)
        {
            result(i, j) = this->data[i][j] * scalar;
        }
    }

    return result;
}

void Matrix::operator=(const Matrix &other)
{
    /*
        This method assigns the values of the given matrix to the current matrix.
    */
    if (this->data != nullptr)
    {
        for (int i = 0; i < this->rows; ++i)
        {
            delete[] this->data[i];
        }
        delete[] this->data;
    }

    this->rows = other.rows;
    this->columns = other.columns;
    this->data = new float *[this->rows];
    for (int i = 0; i < this->rows; ++i)
    {
        this->data[i] = new float[this->columns];

        for (int j = 0; j < this->columns; ++j)
        {
            this->data[i][j] = other.data[i][j];
        }
    }
}

void Matrix::operator=(std::initializer_list<std::initializer_list<float>> values)
{
    /*
        This method assigns the values of the given list of lists to the current matrix.
    */
    if (this->data != nullptr)
    {
        for (int i = 0; i < this->rows; ++i)
        {
            delete[] this->data[i];
        }
        delete[] this->data;
    }

    this->rows = values.size();
    this->columns = values.begin()->size();
    this->data = new float *[this->rows];
    int i = 0;
    for (auto row : values)
    {
        this->data[i] = new float[this->columns];
        int j = 0;
        for (auto value : row)
        {
            this->data[i][j] = value;
            j++;
        }
        i++;
    }
}

void Matrix::print() const
{
    /*
        This method prints the matrix to the standard output
    */
    for (int i = 0; i < this->rows; ++i)
    {
        for (int j = 0; j < this->columns; ++j)
        {
            std::cout << this->data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Matrix::transpose()
{
    /*
        This method transposes the matrix in place.
    */
    Matrix result(this->columns, this->rows);
    for (int i = 0; i < this->rows; ++i)
    {
        for (int j = 0; j < this->columns; ++j)
        {
            result(j, i) = this->data[i][j];
        }
    }
    *this = result;
}
