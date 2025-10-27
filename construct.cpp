#include <iostream>
#include <string>

class Something {
    int a;
    const int b; // use constructor init list for const
    int *ptr = nullptr;
public:
    Something(int a, int b) : b(b),ptr(new int(777)) {  // constructor
        this->a = a;
    }
    Something(int a):Something(a, 0) {}  // using another constructor
    Something():b(10) {} // default constructor
    void print() {
        std::cout << a << " " << b << "\n";
    }
    ~Something() {
        if (ptr)  // for default constructor which not malloc mem
            delete ptr;
        std::cout << "something destroyed" << "\n";
    }
};

int main()
{
    Something obj(5, 6);
    obj.print();
    Something obj2(5);
    obj2.print();
    Something obj3;
    obj3.print();

    Something *obj4 = new Something();
    obj4->print();
    delete obj4;

    return 0;
}