#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void cpu_intensive_function() {
    double result = 0.0;
    for (int i = 0; i < 1000000; i++) {
        result += sin(i * 0.001) * cos(i * 0.001);
    }
    printf("CPU: %f\n", result);
}

void memory_intensive_function() {
    int *array = (int*)malloc(1000000 * sizeof(int));
    for (int i = 0; i < 1000000; i++) {
        array[i] = i * 2;
    }
    
    long long sum = 0;
    for (int i = 0; i < 1000000; i++) {
        sum += array[i];
    }
    printf("Сумма: %lld\n", sum);
    free(array);
}

void branching_function() {
    int counter = 0;
    for (int i = 0; i < 1000000; i++) {
        if (i % 2 == 0) {
            counter += i;
        } else {
            counter -= i;
        }
    }
    printf("Счетчик веток: %d\n", counter);
}

int recursive_function(int n) {
    if (n <= 1) {
        return 1;
    }
    return n + recursive_function(n - 1);
}

int main() {
    for (int i = 0; i < 10; i++) {
        printf("Итерация %d:\n", i + 1);
        cpu_intensive_function();
        memory_intensive_function();
        branching_function();
        
        int rec_result = recursive_function(1000);
        printf("Результат рекурсии: %d\n", rec_result);
        
        printf("---\n");
    }
    
    return 0;
}
