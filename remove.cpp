#include <iostream>
#include <algorithm>
#include <vector>


int main() {

    std::vector<int> vec = {1,2,3,2,4,2,5};
    std::cout << "Seze before: " << vec.size() << "\n";
    auto it_nend = std::remove(vec.begin(), vec.end(), 2);
    // erase here???
    std::cout << "Seze after: " << vec.size() << "\n";
    for (auto elem: vec) {
        std::cout << elem << "\n";
    }

    return 0;
}
