#include "SquareFunction.h"
#include <iostream>

void SquareFunction::setCoefficients(double a, double b, double c) {
    this->a = a;
    this->b = b;
    this->c = c;
}

double SquareFunction::calculate(double x) {
    return a*x*x + b*x + c;
}

void SquareFunction::printFunction() {
    std::cout << "(" << a << ") * x^2 + (" << b << ") * x + (" << c << ")\n";
}
