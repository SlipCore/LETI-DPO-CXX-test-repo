#include <iostream>
#include <string>

class Base {
public:
    virtual double op(double x, double y) {
        return x + y;
    }
    virtual ~Base() {
        std::cout << "DBase\n";
    }
};

class Deriv: public Base {
  public:
    virtual double op(double x, double y) {
        return x * y;
    }
    ~Deriv() {
        std::cout << "DDeriv\n";
    }
};

int main() {
    Base *a = new Base();
    Base *b = new Deriv();
    std::cout << a->op(5,6) << "\n";
    std::cout << b->op(5,6) << "\n";
    delete a;
    delete b;
    return 0;
}
