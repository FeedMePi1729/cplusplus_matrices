#include <iostream>
#include <iterator>
#include "matrices.h"


int main(){

    Matrix a = LinAlg::randomMatrix(3, 3);
    Matrix b = a.transpose();
    Matrix c = LinAlg::mat_mult(a, b);

    std::cout << "Hello world!";
    // a.print();
    // b.print();
    c.print();

}