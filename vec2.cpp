#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    int n;
    std::cin >> n;
    vec.resize(n);

    for (auto& elem: vec) {
        std::cin >> elem;
    }
    for (auto it = vec.rbegin(); it != vec.rend(); it++) {
        std::cout << *it << " ";
    }

    return 0;
}