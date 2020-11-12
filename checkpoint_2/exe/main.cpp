#include <iostream>

#include "functionality.hpp"

int main() {
    std::cout << "Checkpoint 2" << std::endl;
    std::cout << "Hypergeometric probability: " << hypergeometricPmf(10'000, 4'270, 300, 128) << std::endl;
    return 0;
}
