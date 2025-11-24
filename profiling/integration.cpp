// integration.cpp
#include <iostream>
#include <cmath>
#include <functional>

double integrate(std::function<double(double)> func, double a, double b, int n) {
    double h = (b - a) / n;
    double result = 0.0;

    for (int i = 0; i < n; i++) {
        double x = a + i * h;
        result += func(x) * h;
    }

    return result;
}

int main() {
    double result = integrate([](double x) { return std::sin(x); }, 0, M_PI, 1000000000);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
