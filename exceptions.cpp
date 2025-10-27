#include <iostream>
#include <exception>

int my_div(int x, int y)
{
    if (y == 0) {
        throw std::invalid_argument("Div by zero");
    }
    if (x > 1000) {
        throw std::runtime_error("x too big");
    }
    return x / y;
}

int main()
{
    int x ,y;
    std::cin >> x >> y;
    try {
        std::cout << my_div(x, y);
    }
    // catch(std::invalid_argument& e) {
    //     std::cout << e.what();
    // }
    // catch(std::runtime_error& e) {
    //     std::cout << e.what();
    // }
    catch(...) {
        std::cout << "something wrong";
    }
    return 0;
}