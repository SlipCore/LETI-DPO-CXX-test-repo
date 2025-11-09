#include "MyStack.h"
#include <iostream>

int main()
{
    int cap;
    std::cout << "Enter number of elements in stack (capacity): ";
    std::cin >> cap;

    MyStack st1(cap);

    st1.push(1);
    st1.push(2);
    st1.push(3);
    std::cout << "st1: "; st1.state();

    MyStack st2(st1);
    st2.push(4);
    std::cout << "st1: "; st1.state();
    std::cout << "st2: "; st2.state();

    MyStack st3(1);
    st3 = st2;
    st3.push(5);
    std::cout << "st1: "; st1.state();
    std::cout << "st2: "; st2.state();
    std::cout << "st3: "; st3.state();

    // TODO доразобраться с перемещением
    // MyStack st4 = std::move(st1);
    // st4.pop();
    // std::cout << "st1: "; st1.state();
    // std::cout << "st2: "; st2.state();
    // std::cout << "st3: "; st3.state();
    // std::cout << "st4: "; st4.state();

    return 0;
}