#include <stdio.h>

void fast_function() {
    int a = 0;
    for (int i = 0; i < 500000; i++) {a+=i;}
}

void slow_function() {
    int a = 0;
    for (int i = 0; i < 1000000; i++) {a+=i;}
}

int main() {
    fast_function();
    slow_function();
    return 0;
}