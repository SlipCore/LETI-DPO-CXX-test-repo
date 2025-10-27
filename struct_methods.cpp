#include <iostream>
#include <string>

struct Person {
    std::string name;
    int age;

    void say() {
        std::cout << "my name is " << name << ", i'm " << age << "y ears old" << "\n";
    }
    void grow() {
        age++;
    }
};

int main()
{
    Person smith;
    smith.name = "Smith";
    smith.age = 10;
    smith.say();
    smith.grow();
    smith.say();
    return 0;
}