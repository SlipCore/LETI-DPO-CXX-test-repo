#ifndef SQUARE_FUNCTION_H
#define SQUARE_FUNCTION_H

class SquareFunction {
    double a = 1.0;
    double b = -2.0;
    double c = 1.0;
public:
    void setCoefficients(double a, double b, double c);
    double calculate(double x);
    void printFunction();
};

#endif // SQUARE_FUNCTION_H
