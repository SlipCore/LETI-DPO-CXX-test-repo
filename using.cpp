#include <iostream>
#include <string>

class Base {
public:
    void print(int x) {
        std::cout << "Base x = " << x << "\n";
    }
    void print(char c) {
        std::cout << "Base c = " << c << "\n";
    }
};

class Deriv: public Base {
  public:
    using Base::print;  // reusing Base::print methods
    void print(std::string str) {
        std::cout << "Deriv" << str << "\n";
    }  
};

int main() {
    Deriv obj;
    obj.print(111);
    obj.print('R');
    obj.print("some string");
    return 0;
}