#include <iostream>
#include <cctype> // For isalnum
#include <cstring> // For null termination
using namespace std;

class SD {
private:
    char infix[100];
    char postfix[100];

    int precedence(char c) {
        if (c == '^') return 3;
        if (c == '*' || c == '/') return 2;
        if (c == '+' || c == '-') return 1;
        return 0; // Invalid operator
    }

public:
    void get() {
        cout << "Enter infix expression: ";
        cin >> infix;
    }

    void infixToPostfix() {
        char stack[100];
        int top = -1;
        int j = 0;

        for (int i = 0; infix[i] != '\0'; i++) {
            char c = infix[i];

            if (isalnum(c)) {
                postfix[j++] = c; // Add operand to postfix
            } else if (c == '(') {
                stack[++top] = c; // Push '(' onto stack
            } else if (c == ')') {
                while (top != -1 && stack[top] != '(') {
                    postfix[j++] = stack[top--]; // Pop until '('
                }
                top--; // Remove '(' from stack
            } else {
                while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                    postfix[j++] = stack[top--]; // Pop higher/equal precedence operators
                }
                stack[++top] = c; // Push current operator
            }
        }

        // Pop remaining operators from the stack
        while (top != -1) {
            postfix[j++] = stack[top--];
        }
        postfix[j] = '\0'; // Null terminate the postfix expression
    }

    void displayPostfix() {
        cout << "Postfix expression: " << postfix << endl;
    }
};

int main() {
    SD a;
    int choice;

    do {
        cout << "\n1. Input infix expression\n2. Convert to postfix\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            a.get();
            break;
        case 2:
            a.infixToPostfix();
            a.displayPostfix();
            break;
        case 3:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
