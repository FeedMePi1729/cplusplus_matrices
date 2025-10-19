#pragma once
#include <cstddef>
#include <vector>


class Matrix {
public:
    Matrix(std::size_t rows, std::size_t cols)
        : rows_(rows), cols_(cols), data_(rows * cols, 0.0) {}

    double& set(std::size_t row, std::size_t col);
    const double& at(std::size_t row, std::size_t col) const;
    Matrix shape() const;
    void print() const;
    void randomInitialise();
    std::size_t nRows() const;
    std::size_t nCols() const;
    Matrix transpose() const;
    
private:
    std::size_t rows_;
    std::size_t cols_;
    std::vector<double> data_;
};

namespace LinAlg {
Matrix mat_mult(const Matrix& lhs, const Matrix& rhs);
Matrix randomMatrix(const std::size_t rows, const std::size_t cols);
}