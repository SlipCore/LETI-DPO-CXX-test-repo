// error_codes.cpp
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <exception>
#include "task1_1.hpp"

Result DivideIntegers(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return MakeSuccess(a / b);
}

Result OpenAndReadFile(const std::string& filename, std::vector<char>& buffer) {

    if (filename.empty()) {
        throw std::invalid_argument("Empty filename");
    }
    
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        throw std::runtime_error("File not found");
    }
    
    std::streamsize size = file.tellg();
    if (size < 0) {
        throw std::runtime_error("File not found");
    }
    
    file.seekg(0, std::ios::beg);
    buffer.resize(static_cast<size_t>(size));
    
    if (!file.read(buffer.data(), size)) {
        throw std::runtime_error("File read error");
    }
    
    return MakeSuccess(0);
}

Result ProcessConfigFile(const std::string& configPath) {
    std::vector<char> buffer;
    Result readRes = OpenAndReadFile(configPath, buffer);

    // some mock processing here
    
    std::cout << "Config processed successfully, size " << buffer.size() << " bytes\n";
    return MakeSuccess(1);
}

int main() {
    
    try {
        Result resDiv = DivideIntegers(5, 0);
        std::cout << GetErrorString(resDiv.code) << "\n";
    // } catch (std::exception &e) {
    //     std::cout << "invalid argument exception: " << e.what() << "\n";
    } catch (std::exception &e) {
        std::cout << "exception: " << e.what() << "\n";
    } catch (...) {
        std::cout << "unknown error exception\n";
    }

    try {
        Result resCfg = ProcessConfigFile("config.dat");
        std::cout << GetErrorString(resCfg.code) << "\n";
    // } catch (std::invalid_argument &e) {
    //      std::cout << "invalid argument exception: " << e.what() << "\n";
    // } catch (std::runtime_error &e) {
    //      std::cout << "runtime error exception: " << e.what() << "\n";
    } catch (std::exception &e) {
        std::cout << "exception: " << e.what() << "\n";
    } catch (...) {
        std::cout << "unknown error exception\n";
    }

    return 0;
}
