#include <stdio.h>
#define SIZE 1000

int main() {
    int arr[SIZE][SIZE];
    // Неэффективный доступ к памяти (промахи кэша)
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            arr[j][i] = i + j; // Непоследовательный доступ
        }
    }


    // Эффективный доступ к памяти (промахи кэша)
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            arr[i][j] = i + j; // Последовательный доступ?
        }
    }
    return 0;
}
