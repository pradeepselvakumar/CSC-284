#include "MathUtils.h"
#include <stdexcept>

int MathUtils::Add(int a, int b) {
    return a + b;
}

int MathUtils::Subtract(int a, int b) {
    return a - b;
}

int MathUtils::Multiply(int a, int b) {
    return a * b;
}

int MathUtils::Divide(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("Cannot divide by zero");
    }
    return a / b;
}
