#include <iostream>

#include <boost/program_options.hpp>

#include "functionality.hpp"
#include "functionality_eigen.hpp"

namespace po = boost::program_options;

int main() {

    std::cout << "Checkpoint 3" << std::endl;
    std::cout << "Hypergeometric probability: " << hypergeometricPmf(10'000, 4'270, 300, 128) << std::endl;
    std::cout << "Random matrix: " << std::endl;
    printRandomMatrix();

    // Use boost program options
    {
        po::options_description desc("Allowed options");
        desc.add_options()
                ("help", "produce help message")
                ("compression", po::value<int>(), "set compression level");

        po::variables_map vm;

        std::cout << desc << std::endl;
    }

    // int unused_variable = 0;

    return 0;
}
