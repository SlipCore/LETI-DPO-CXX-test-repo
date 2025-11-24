#include <stdlib.h>

void leak() {
    char* pointer = malloc(40); // Утечка: не освобождаем память
}

void invalid_access() {
    int* arr = malloc(3 * sizeof(int));
    arr[5] = 10; // Выход за границы массива
    free(arr);
}

int main() {
    leak();
    invalid_access();
    return 0;
}