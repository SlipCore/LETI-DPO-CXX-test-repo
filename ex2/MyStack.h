#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
#include <exception>
#include <string.h>

class MyStack {
private:
    int capacity;
    int size;
    int *data;
public:
    MyStack(int capacity) : capacity(capacity), size(0), data(new int[capacity]) {
        std::cout << "Create stack with capacity = " << capacity << "\n";
    }
    MyStack(const MyStack& stack) : capacity(stack.capacity), size(stack.size), data(new int[capacity]) {
        std::cout << "Copy constructor\n";
        memcpy(data, stack.data, size * sizeof(int));
    }

    // TODO доразобраться с перемещением
    // MyStack(MyStack&& stack) : capacity(stack.capacity), size(stack.size), data(new int[capacity]) {
    //     std::cout << "Move constructor\n";
    //     data = std::move(stack.data);
    // }
    // MyStack(MyStack&& stack) : capacity(stack.capacity), size(stack.size), data(nullptr) {
    //     std::cout << "Move constructor\n";
    //     std::swap(data, stack.data);
    // }

    ~MyStack() {
        delete data;
        std::cout << "Destroy stack\n";
    }
    MyStack& operator=(const MyStack& stack) {
        std::cout << "Copy =\n";
        if (this != &stack) {  // проверка на самоприсваивание
            delete data;
            capacity = stack.capacity;
            size = stack.size;
            data = new int[capacity];
            memcpy(data, stack.data, size * sizeof(int));
        }
        return *this;
    }
    MyStack& operator=(MyStack&& stack) {
        std::cout << "Move =\n";
        data = std::move(stack.data);
        return *this;
    }

    void push(int x) {
        if (size >= capacity) {
            throw std::runtime_error("stack is full, can not push");
        } else {
            data[size] = x;
            size++;
        }
    }
    double pop() {
        if (size == 0) {
            throw std::runtime_error("empty stack, can not pop");
        } else {
            double x = data[size-1];
            size--;
            return x;
        }
    }
    void state() {
        std::cout << "Stack with " << size << " of " << capacity << " elements: ";
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << "\n";
    }
};

#endif // MYSTACK_H
