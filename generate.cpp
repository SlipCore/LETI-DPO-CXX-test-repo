#include <iostream>
#include <algorithm>
#include <vector>

int gen_func() {
    static int var = 1;
    var += var;
    return var;
}

int main() {

    std::vector<int> vec(30);
    std::generate(vec.begin(), vec.end(), gen_func);

    for (auto elem: vec) {
        std::cout << elem << "\n";
    }

    return 0;
}
