#include <iostream>

class Secret {
    int *ptr;
public:
    Secret(int value) : ptr(new int(value)) {}
    ~Secret() {
        delete ptr;
    }

    Secret(const Secret& obj) {  // copy constructor
        std::cout << "Copy constructor\n";
        ptr = new int(*obj.ptr);
    }

    Secret(Secret&& obj) : ptr(nullptr) {  // move constructor
        std::cout << "Move constructor\n";
        std::swap(ptr, obj.ptr);
    }
    // Secret& operator = (Secret&& obj) {  // move operator
    //     std::swap(ptr, obj.ptr);
    //     return *this;
    // }

    int & get() {
        return *ptr;
    }
};

int main() {
    Secret s(40);
    // Secret r = s;
    Secret r = std::move(s);
    //s.get() = 10;
    // std::cout << "origin " << s.get() << "\n";
    std::cout << "new " << r.get() << "\n";
}