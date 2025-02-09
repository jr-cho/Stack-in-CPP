#include <iostream>

template <typename T>
struct Stack {
    int top, capacity;
    T* arr;

    Stack(int size){
        arr = new T[size];
        capacity = size;
        top = -1;
    }

    ~Stack(){
        delete[] arr;
        std::cout << "Stack Destroyed\n";
    }

    bool isEmpty(){
        if (top < 0){
            return true;
        }
        else {
            return false;
        }
    }

    bool isFull(){
        if (top >= capacity - 1){
            return true;
        }
        else {
            return false;
        }
    }

    void push(T data){
        if(!isFull()){
            arr[++top] = data;
            std::cout << "Pushed: " << data << std::endl;
        }
        else{
            std::cout << "WARNING: Stack Overflow!" << std::endl;
        }
    }

    T pop(){
        T temp = arr[top];
        top--;
        return temp;
    }

    T peek(){
        return arr[top];
    }
};

int main() {
    Stack<int> s(3);
    s.push(10);
    s.push(20);
    s.push(30);
    std::cout << "Peek: " << s.peek() << std::endl;
    std::cout << "Pop: " << s.pop() << std::endl;
}
