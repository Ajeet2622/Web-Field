#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;          // Array to store stack elements
    int top;           // Index of the top element
    int capacity;      // Maximum capacity of the stack

public:
    // Constructor to initialize stack
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;  // Stack is empty initially
    }

    // Destructor to clean up memory
    ~Stack() {
        delete[] arr;
    }

    // Function to add an element to the stack
    void push(int x) {
        if (top == capacity - 1) {
            cout << "Stack overflow! Cannot push " << x << endl;
            return;
        }
        arr[++top] = x;
        cout << "Pushed " << x << " into the stack" << endl;
    }

    // Function to remove and return the top element of the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow! No elements to pop" << endl;
            return -1;
        }
        cout << "Popped " << arr[top] << " from the stack" << endl;
        return arr[top--];
    }

    // Function to return the top element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty! No elements to peek" << endl;
            return -1;
        }
        return arr[top];
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Function to get the size of the stack
    int size() {
        return top + 1;
    }
};

int main() {
    Stack stack(5);  // Create a stack with capacity 5

    // Perform basic stack operations
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    cout << "Top element is: " << stack.peek() << endl;

    stack.pop();
    stack.pop();

    cout << "Top element after popping two elements: " << stack.peek() << endl;

    if (stack.isEmpty()) {
        cout << "Stack is empty!" << endl;
    } else {
        cout << "Stack is not empty!" << endl;
    }

    return 0;
}
