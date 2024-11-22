#include <iostream>
#include <cctype>  // For isalnum
#include <cstring> // For string manipulation
using namespace std;

class SD {
private:
    char infix[100];  // To store the input infix expression
    char prefix[100]; // To store the converted prefix expression

    // Function to determine the precedence of operators
    int precedence(char c) {
        if (c == '^') return 3;
        if (c == '*' || c == '/') return 2;
        if (c == '+' || c == '-') return 1;
        return 0; // Non-operator
    }

public:
    // Function to accept the infix expression from the user
    void get() {
        cout << "Enter infix expression: ";
        cin >> infix;
    }

    // Function to convert infix to prefix
    void infixToPrefix() {
        // Step 1: Reverse the infix expression
        int len = strlen(infix);
        for (int i = 0; i < len / 2; i++) {
            char temp = infix[i];
            infix[i] = infix[len - i - 1];
            infix[len - i - 1] = temp;
        }

        // Step 2: Replace '(' with ')' and vice versa
        for (int i = 0; i < len; i++) {
            if (infix[i] == '(')
                infix[i] = ')';
            else if (infix[i] == ')')
                infix[i] = '(';
        }

        // Step 3: Convert the modified infix to postfix
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
                while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                    prefix[j++] = stack[top--]; // Pop operators with higher precedence
                }
                stack[++top] = c; // Push current operator onto stack
            }
        }

        while (top != -1) {
            prefix[j++] = stack[top--]; // Pop all operators from stack
        }
        prefix[j] = '\0'; // Null terminate the prefix expression

        // Step 4: Reverse the prefix expression
        for (int i = 0; i < j / 2; i++) {
            char temp = prefix[i];
            prefix[i] = prefix[j - i - 1];
            prefix[j - i - 1] = temp;
        }
    }

    // Function to display the prefix expression
    void displayPrefix() {
        cout << "Prefix expression: " << prefix << endl;
    }
};

int main() {
    SD a;
    int choice;

    do {
        cout << "\n1. Input infix expression\n2. Convert to prefix\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            a.get();
            break;
        case 2:
            a.infixToPrefix();
            a.displayPrefix();
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
