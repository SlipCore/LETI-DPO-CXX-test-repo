#include <iostream>

class Base {
public:
    void f() {
        std::cout << "Base\n";
    }
};

class Deriv: public Base {
  public:
    void f() {
        std::cout << "Deriv\n";
    }  
};

class Final: public Deriv {
  public:
    void f() {
        std::cout << "Final\n";
    }  
};

int main() {
    Final obj;
    obj.f();
    obj.Deriv::f();
    obj.Base::f();
    return 0;
}