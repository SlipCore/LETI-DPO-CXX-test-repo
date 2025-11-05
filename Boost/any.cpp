#include <iostream>
#include <vector>
#include <string>
#include <boost/any.hpp>

int main() {

    std::vector<boost::any> collection;

    collection.emplace_back(42);
    collection.emplace_back("Hello");  // const char* !
    collection.emplace_back(3.14f);
    collection.emplace_back(std::string("Ocean"));
    collection.emplace_back((double)3.14);

    for (const auto& item: collection) {
        if (item.type() == typeid(int)) {
            std::cout << "Int: " << boost::any_cast<int>(item) << "\n";
        } else if (item.type() == typeid(const char*)) {
            std::cout << "C string: " << boost::any_cast<const char*>(item) << "\n";
        } else if (item.type() == typeid(float)) {
            std::cout << "Float: " << boost::any_cast<float>(item) << "\n";
        } else if (item.type() == typeid(std::string)) {
            std::cout << "String: " << boost::any_cast<std::string>(item) << "\n";
        } else {
            std::cout << "bad type\n";
        }
    }

    return 0;
}