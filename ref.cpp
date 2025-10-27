#include <iostream>

void func(int &value) {
    std::cout << "reference lvalue" << "\n";
}
void func(int &&value) {
    std::cout << "reference rvalue" << "\n";
}
void func(const int &value) {
    std::cout << "const reference lvalue" << "\n";
}


int main() {
    int x = 10;
    func(x);  // lvalue

    func(5);  // rvalue

    const int y = 10;
    func(y);  // const lvalue
}
