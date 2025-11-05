#include <iostream>
#include <vector>  //STL

// custom operator for vector printing
template<typename T>
std::ostream& operator<< (std::ostream& out, std::vector<T>& vec) {
    std::cout << "size=" << vec.size() << " capacity=" << vec.capacity() << " [";
    for (int i = 0; i < vec.size(); i++) {
        out << vec.at(i) << " ";
    }
    return out << "]\n";
};

int main() {
    std::vector vec = {'a', 'b', 'c'};  // std::vector<char>
    std::cout << vec;
    
    vec.push_back('d');  // +1 element, but capacity doubled
    std::cout << vec;

    vec.shrink_to_fit();  // free unused memory
    std::cout << vec;

    vec.clear();  // allocated memory preserved
    std::cout << vec;

    // iterators
    auto it1 = vec.begin();  // still can access first element
    std::cout << *it1 << '\n';
    it1++;
    std::cout << *it1 << '\n';

    std::vector<int> vec2 = {};
    std::cout << vec2;              // template operator<< still works!
    auto it2 = vec2.begin();
    //std::cout << *it2 << '\n';    // error! non existing element

    return 0;
}