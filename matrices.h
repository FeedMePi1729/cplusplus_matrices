#pragma once
#include <cstddef>
#include <vector>


namespace LinAlg {
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
private:
    std::size_t rows_;
    std::size_t cols_;
    std::vector<double> data_;
};


Matrix mat_mult(const Matrix& lhs, const Matrix& rhs);

}