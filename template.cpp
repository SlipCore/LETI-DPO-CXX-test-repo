#include <iostream>

template<typename T>
class MyArr {
    T *arr;
    int n;
public:
    MyArr(int n):n(n) {
        arr = new T[n];
    }
    ~MyArr() {
        delete arr;
    }
    int size() {
        return n;
    }
    T& get(int i) {
        return arr[i];
    }
};

struct Smth {
    int a;
    float b;
    friend std::ostream& operator<< (std::ostream& out, Smth& obj) {
        return out << '{' << obj.a << ", " << obj.b << '}';
    };
};

template<typename T>
void print(T obj) {
    std::cout << obj << '\n';
}

int main() {
    MyArr<char> arr1(5);
    for (int i = 0; i < arr1.size(); i++) {
        arr1.get(i) = 'A' + i;
    }

    print(10);
    print("Hell World");

    Smth something = {1, 2.5};
    print(something);

    return 0;
}