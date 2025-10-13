#include <iostream>


int main() {
    std::string textToPrint = "Hello, World!";
    for (size_t i = 0; i < 5; i++) {
        std::cout << i << std::endl;
    }
    
    std::cout << textToPrint << std::endl;
    return 0;
}
