#include "SquareFunction.h"
#include <iostream>

int main()
{
    double a, b, c;
    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;
    std::cout << "c = ";
    std::cin >> c;
    
    SquareFunction func;
    func.setCoefficients(a, b, c);
    
    int x1, x2;
    std::cout << "x1 = ";
    std::cin >> x1;
    do {
        std::cout << "x2 = ";
        std::cin >> x2;
        if (x2 < x1) {
            std::cout << "x2 shoud be equal or greater than x1" << "\n";
        }
    } while (x2 < x1);   
    
    func.printFunction();
    for (int x = x1; x <= x2; x++) {
        std::cout << "func(" << x << ") = " << func.calculate(x) << "\n";
    }
    return 0;
}