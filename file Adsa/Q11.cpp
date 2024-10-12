#include <iostream>
using namespace std;

#define MAX 100 // Defining maximum size for the stack

// Stack implementation
class Stack {
    int arr[MAX]; // Array to store elements
    int top;      // Top of the stack

public:
    Stack() { top = -1; } // Constructor initializes the stack

    void push(int x) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow\n";
        } else {
            arr[++top] = x;
        }
    }

    int pop() {
        if (top < 0) {
            cout << "Stack Underflow\n";
            return 0;
        } else {
            return arr[top--];
        }
    }

    bool isEmpty() {
        return (top < 0);
    }
};

// Function to manually convert a char to an integer
int charToInt(char ch) {
    return ch - '0'; // Convert character '0'-'9' to an integer
}

// Function to evaluate a postfix expression manually
int evaluatePostfix(string expr) {
    Stack s; // Create an instance of the Stack

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        // Check if the character is a digit (manually)
        if (ch >= '0' && ch <= '9') {
            int num = charToInt(ch); // Convert char to int manually
            s.push(num); // Push the operand to the stack
        } else {
            // It's an operator, pop two operands
            int operand2 = s.pop();
            int operand1 = s.pop();
            int result;

            // Perform the operation manually
            switch (ch) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    cout << "Invalid operator: " << ch << endl;
                    return -1;
            }
            s.push(result); // Push the result back onto the stack
        }
    }

    // The final result is the only element left in the stack
    return s.pop();
}

int main() {
    string expression;
    cout << "Enter a postfix expression: ";
    cin >> expression;

    int result = evaluatePostfix(expression);
    cout << "Result: " << result << endl;

    return 0;
}
