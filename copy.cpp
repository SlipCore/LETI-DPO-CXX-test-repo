#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <fstream>

bool isLess10(int x) {
    return x < 10;
};

int main() {

    std::vector<int> vec;
    std::copy(std::istream_iterator<int>(std::cin),
              std::istream_iterator<int>(),
              std::back_inserter(vec));  // press Ctrl+D to end istream

    // to stdout
    std::copy(vec.begin(),
              vec.end(),
              std::ostream_iterator<int>(std::cout, " "));  

    // to file with condition
    std::ofstream fout("out.txt", std::ios_base::app);
    std::copy_if(vec.begin(),
                 vec.end(),
                 std::ostream_iterator<int>(fout, "\n"),
                 isLess10);  

    return 0;
}
