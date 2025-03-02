#include <iostream>

template <typename T>
class Vector {
    T* arr;
    size_t capacity_;
public:
    Vector() : arr(nullptr), capacity_(0) {}

    ~Vector() {
        delete[] arr;
    }

    void reserve(size_t n) {
        if(n > capacity_) {
            delete[] arr;
            arr = new T[n];
            capacity_ = n;
        }
    }

    T& operator[](size_t index) {
        return arr[index];
    }
    const T& operator[](size_t index) const {
        return arr[index];
    }
};

template <typename T>
class Stack {
    Vector<T> data;
    int top;
    int capacity;

public:
    Stack(int capacity) : capacity(capacity), top(-1) {
        data.reserve(capacity);
    }

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
      return top == capacity - 1;
    }

    int size() const {
        return top + 1;
    }

    void push(const T& value) {
        if (isFull()) {
            std::cout << "WARNING: STACK OVERFLOW!\n";
        }
        data[++top] = value;
    }

    T pop() {
        if (isEmpty()) {
           std::cout << "WARNING: STACK OVERFLOW!\n";
        }
        return data[top--];
    }

    T peek() const {
        if (isEmpty()) {
           std::cout << "WARNING: STACK OVERFLOW!\n";
        }
        return data[top];
    }

    void print() const {
        std::cout << "STACK: ";
        for (int i = 0; i <= top; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Stack<int> myStack(5);

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);

    myStack.print();

    std::cout << "TOP ELEMENT: " << myStack.peek() << std::endl; 
    std::cout << "STACK SIZE: " << myStack.size() << std::endl;

    std::cout << "POPPED ELEMENT: " << myStack.pop() << std::endl;
    std::cout << "POPPED ELEMENT: " << myStack.pop() << std::endl;

    std::cout << "STACK SIZE: " << myStack.size() << std::endl;

    return 0;
} 
