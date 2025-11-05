#include <iostream>
#include <algorithm>
#include <vector>

int main() {

    int n = 10;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i*2;
    }

    std::vector<int> vec;
    std::copy(arr, arr+n, std::back_inserter(vec));  // pointers used as iterators

    for (auto elem: vec) {
        std::cout << elem << "\n";
    }

    return 0;
}
