#include <iostream>
#include <algorithm>
#include <vector>

struct Person {
    std::string name;
    int age;
};

std::string getPersonString(Person &p) {
    std::string str = "Name: " + p.name + ", age: " + std::to_string(p.age);
    return str;
};

void printPerson(Person &p) {
    std::cout << getPersonString(p) <<  "\n";
};


bool isRomeo(Person &p) {
    return p.name == "Romeo";
}

int main() {

    std::vector<Person> vec = {{"Romeo", 20}, {"Juliete", 18}};
    std::for_each(vec.begin(), vec.end(), printPerson);

    auto it = std::find_if(vec.begin(), vec.end(), isRomeo);
    if (it != vec.end()) {
        std::cout << it->name << "\n";
    } else {
        std::cout << "Not found\n";
    }

    std::vector<std::string> str_vec;
    std::transform(vec.begin(), vec.end(), std::back_inserter(str_vec), getPersonString);
    for (auto str: str_vec) {
        std::cout << str << "\n";
    }

    return 0;
}
