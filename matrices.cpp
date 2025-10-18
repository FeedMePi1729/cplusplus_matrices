#include <stdexcept>
#include <iostream>
#include <random>
#include "matrices.h"

double& LinAlg::Matrix::set(std::size_t row, std::size_t col) {

    // This function returns a reference so that it does not over-ride the 
    // main object with the new data, but rather changes the object in place.

    if (row >= rows_ || col >= cols_) {
        throw std::out_of_range("Matrix::set indices out of range");
    }
    return data_[row * cols_ + col];
}

const double& LinAlg::Matrix::at(std::size_t row, std::size_t col) const {

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

LinAlg::Matrix LinAlg::Matrix::shape() const {
    // Returnst the shape of the matrix in a 2x1 format
    Matrix dims(2, 1);

    dims.set(0, 0) = Matrix::nRows();
    dims.set(1, 0) = Matrix::nCols();

    return dims;
}

void LinAlg::Matrix::print() const {

    const std::size_t rows = nRows();
    const std::size_t cols = nCols();

    for (std::size_t row = 0; row < rows; row++){ // per row

        std::cout << "\n [";

        for (std::size_t col = 0; col < cols; col++){ // per column

            std::cout << Matrix::at(row, col) << ", ";
        };

        std::cout << "], \n ";
    };

};

void LinAlg::Matrix::randomInitialise(){

    // Randomly initialises the matrix with random float between 0, 1.

    std::mt19937 rng(std::random_device{}());
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    for (std::size_t row = 0; row < nRows(); row++){
        for (std::size_t col = 0; col < nCols(); col++){
            set(row, col) = dist(rng);
        }
    }
}

std::size_t LinAlg::Matrix::nRows() const {
    return rows_;
}

std::size_t LinAlg::Matrix::nCols() const {
    return cols_;
}

LinAlg::Matrix LinAlg::mat_mult(
    const LinAlg::Matrix& lhs, 
    const LinAlg::Matrix& rhs
) {

    // we do not return a reference in this case because the "result" that we are
    // referencing immediately dies after we go out of scope of the function.

    // Therefore, if we return a reference, itll point to something that does not exist
    // causing strange behavior.
    
    if (lhs.nCols() != rhs.nRows()) {
        throw std::invalid_argument("mat_mult dimension mismatch");
    }
    LinAlg::Matrix result(lhs.nRows(), rhs.nCols());
    for (std::size_t row = 0; row < lhs.nRows(); ++row) {
        for (std::size_t col = 0; col < rhs.nCols(); ++col) {
            double sum = 0.0;
            for (std::size_t k = 0; k < lhs.nCols(); ++k) {
                sum += lhs.at(row, k) * rhs.at(k, col);
            }
            result.set(row, col) = sum;
        }
    }
    return result;
}
