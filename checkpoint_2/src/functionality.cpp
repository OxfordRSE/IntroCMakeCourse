#include "functionality.hpp"

#include <cassert>
#include <cmath>


double hypergeometricPmf(const int populationSize, const int numberOfSuccesses, const int sampleSize,
                         const int observedSuccesses) {

    assert(populationSize >= 0);
    assert(numberOfSuccesses >= 0);
    assert(sampleSize >= 0);
    assert(observedSuccesses >= 0);

    assert(populationSize >= numberOfSuccesses);

    assert(observedSuccesses <= sampleSize);
    assert(observedSuccesses <= numberOfSuccesses);

    const double num1 = std::lgamma(1.0 + numberOfSuccesses);
    const double num2 = std::lgamma(1.0 + sampleSize);
    const double num3 = std::lgamma(1.0 + populationSize - numberOfSuccesses);
    const double num4 = std::lgamma(1.0 + populationSize - sampleSize);

    const double den1 = std::lgamma(1.0 + observedSuccesses);
    const double den2 = std::lgamma(1.0 + populationSize);
    const double den3 = std::lgamma(1.0 + numberOfSuccesses - observedSuccesses);
    const double den4 = std::lgamma(1.0 + sampleSize - observedSuccesses);
    const double den5 = std::lgamma(1.0 + populationSize + observedSuccesses - numberOfSuccesses - sampleSize);

    return std::exp(num1 + num2 + num3 + num4 - den1 - den2 - den3 - den4 - den5);
}
