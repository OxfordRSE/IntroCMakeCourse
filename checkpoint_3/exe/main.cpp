#include <iostream>

#include "functionality.hpp"
#include "functionality_eigen.hpp"

int main() {
    std::cout << "Checkpoint 3" << std::endl;
    std::cout << "Hypergeometric probability: " << hypergeometricPmf(10'000, 4'270, 300, 128) << std::endl;
    std::cout << "Random matrix: " << std::endl;
    printRandomMatrix();

    return 0;
}
