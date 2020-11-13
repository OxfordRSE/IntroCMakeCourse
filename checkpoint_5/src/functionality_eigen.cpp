#include <iostream>

#include <Eigen/Core>


void printRandomMatrix() {
    std::cout << Eigen::MatrixXd::Random(4, 4);
}
