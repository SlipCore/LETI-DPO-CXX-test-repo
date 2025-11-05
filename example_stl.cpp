#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template<typename T>
void f(T begin, T end) {
    std::for_each(begin ,end, [](int& x) {x *= x});
    std::copy(begin, end, std::ostreambuf_iterator<double>(std::cout, " "));
}

int main() {

    std::vector vec = {1,2,3,4,5};
    std::list lst = {1,2,3,4,5};
    f(vec.begin(), vec.end());
    f(lst.begin(), lst.end());

    for (auto elem: vec) {
        std::cout << elem << "\n";
    }
    for (auto elem: lst) {
        std::cout << elem << "\n";
    }

    return 0;
}
