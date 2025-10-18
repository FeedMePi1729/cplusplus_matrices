#include <iostream>
#include <iterator>
#include "matrices.h"


int main(){

    LinAlg::Matrix a(30, 20);
    LinAlg::Matrix b(20, 30);

    a.randomInitialise();
    b.randomInitialise();

    LinAlg::mat_mult(a, b).print();
}