#include <iostream>
#include <string>

class Counter {
    static int count;
public:
    void inc() {
        count++;
    }
    static int getCount() {
        return count;
    }
};
int Counter::count = 5;  // !!!

int main()
{
    Counter c1;
    Counter c2;
    c1.inc();
    std::cout << c2.getCount() << "\n";
    std::cout << Counter::getCount() << "\n";  // static method
    return 0;
}