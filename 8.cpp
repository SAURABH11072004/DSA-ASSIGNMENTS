#include <iostream>
#include <stdlib.h> // For atof

using namespace std;

class Infix {
private:
    char infix[100];    // Input infix expression
    char postfix[100];  // Converted postfix expression
    char prefix[100];   // Converted prefix expression

public:
    void getData() {
        cout << "Enter infix expression: ";
        cin >> infix;
    }

    void infixToPostfix() {
        char stack[100];
        int top = -1;
        int j = 0;

        for (int i = 0; infix[i] != '\0'; i++) {
            char c = infix[i];

            if (isalnum(c)) { // Check if c is an operand
                postfix[j++] = c; // Add operand to postfix
            } else if (c == '(') {
                stack[++top] = c; // Push '(' onto stack
            } else if (c == ')') {
                while (top != -1 && stack[top] != '(') {
                    postfix[j++] = stack[top--]; // Pop stack until '('
                }
                top--; // Remove '(' from stack
            } else {
                while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                    postfix[j++] = stack[top--]; // Pop operators with higher or equal precedence
                }
                stack[++top] = c; // Push current operator onto stack
            }
        }

        while (top != -1) {
            postfix[j++] = stack[top--]; // Pop all operators from stack
        }
        postfix[j] = '\0'; // Null terminate the postfix expression
    }

    void infixToPrefix() {
        // Reverse the infix expression
        int len = 0;
        while (infix[len] != '\0') len++; // Calculate length of infix

        for (int i = 0; i < len / 2; i++) {
            char temp = infix[i];
            infix[i] = infix[len - i - 1];
            infix[len - i - 1] = temp;
        }

        // Change '(' to ')' and vice versa
        for (int i = 0; i < len; i++) {
            if (infix[i] == '(') infix[i] = ')';
            else if (infix[i] == ')') infix[i] = '(';
        }

        char stack[100];
        int top = -1;
        int j = 0;

        for (int i = 0; i < len; i++) {
            char c = infix[i];

            if (isalnum(c)) {
                prefix[j++] = c; // Add operand to prefix
            } else if (c == '(') {
                stack[++top] = c; // Push '(' onto stack
            } else if (c == ')') {
                while (top != -1 && stack[top] != '(') {
                    prefix[j++] = stack[top--]; // Pop stack until '('
                }
                top--; // Remove '(' from stack
            } else {
                while (top != -1 && precedence(stack[top]) > precedence(c)) {
                    prefix[j++] = stack[top--]; // Pop operators with higher precedence
                }
                stack[++top] = c; // Push current operator onto stack
            }
        }

        while (top != -1) {
            prefix[j++] = stack[top--]; // Pop all operators from stack
        }
        prefix[j] = '\0'; // Null terminate the prefix expression

        // Reverse the prefix expression
        for (int i = 0; i < j / 2; i++) {
            char temp = prefix[i];
            prefix[i] = prefix[j - i - 1];
            prefix[j - i - 1] = temp;
        }
    }

    // Getter methods for postfix and prefix expressions
    const char* getPostfix() {
        return postfix;
    }

    const char* getPrefix() {
        return prefix;
    }

private:
    // Function to check operator precedence
    int precedence(char c) {
        if (c == '^') return 3;
        if (c == '*' || c == '/') return 2;
        if (c == '+' || c == '-') return 1;
        return -1; // Non-operator
    }
};

int main() {
    Infix expr;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Input Infix Expression\n";
        cout << "2. Convert Infix to Postfix\n";
        cout << "3. Convert Infix to Prefix\n";
        cout << "4. Exit\n"; // Removed evaluation options
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                expr.getData();
                break;
            case 2:
                expr.infixToPostfix();
                cout << "Postfix Expression: " << expr.getPostfix() << endl;
                break;
            case 3:
                expr.infixToPrefix();
                cout << "Prefix Expression: " << expr.getPrefix() << endl;
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
