#include <stdexcept>
#include <iostream>
#include "matrices.h"

double& Matrix::set(std::size_t row, std::size_t col) {

    // This function is used to set the value o

    if (row >= rows_ || col >= cols_) {
        throw std::out_of_range("Matrix::at indices out of range");
    }
    return data_[row * cols_ + col];
}

const double& Matrix::at(std::size_t row, std::size_t col) const {

    // since this function returns a const - this means that the value 
    // that is returned cannot be modified through the reference it returns.

    // The trailing const ensures that the overload of the other at function does 
    // NOT mutate the matrix object. You cannot modifiy the reference itself using this 
    // overload.

    // so for example, Matrix::at(2, 3) = 5; would call the other function,
    // not this one.

    if (row >= rows_ || col >= cols_) {
        throw std::out_of_range("Matrix::at indices out of range");
    }
    return data_[row * cols_ + col];
}

Matrix Matrix::shape() const {
    // Returnst the shape of the matrix in a 2x1 format
    Matrix dims(2, 1);

    dims.set(0, 0) = Matrix::nRows();
    dims.set(1, 0) = Matrix::nCols();

    return dims;
}

void Matrix::print() const {

    Matrix dims = Matrix::shape();

    const int& rows = dims.at(0, 0);
    const int& cols = dims.at(1, 0);

    for (int row = 0; row < rows; row++){ // per row

        std::cout << "\n";

        for (int col = 0; col < cols; col++){ // per column

            std::cout << " | " << Matrix::at(row, col);
        };

        std::cout << " | ";
        std::cout << "\n";
    };

};

std::size_t Matrix::nRows() const {
    return rows_;
}

std::size_t Matrix::nCols() const {
    return cols_;
}
