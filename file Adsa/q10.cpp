#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string str) {
    stack<char> s;

    for (char ch : str) {
        if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            if (s.empty() || s.top() != '(') {
                return false; // Unmatched closing parenthesis
            }
            s.pop();
        }
    }

    return s.empty(); // Check if all opening parentheses are matched
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    if (isBalanced(input)) {
        cout << "The parentheses are balanced.\n";
    } else {
        cout << "The parentheses are not balanced.\n";
    }

    return 0;
}
