#include <iostream>
using namespace std;

class Polynomial;

class Node {
    int coeff; // Coefficient of the polynomial term
    int pow;   // Exponent of the polynomial term
  
public:
    // Constructor to initialize the node and set next to NULL
    Node* next;
    Node() {
        next = NULL;
    }

    // Method to read the coefficient and exponent from the user
    void read(int termNumber) { // Added termNumber parameter
        cout << "TERM " << termNumber << " - Enter coefficient: ";
        cin >> coeff;
        cout << "Enter power: ";
        cin >> pow;
    }

    // Method to display the term in the form "coeff x^pow"
    void display() {
        cout << coeff << "x^" << pow;
    }

    // Friend function declaration to add two polynomials
    friend class Polynomial;
    friend void addPolynomial(Polynomial p1, Polynomial p2);
};

// Polynomial class to represent a polynomial using a linked list of Nodes
class Polynomial {
    Node* head;

public:
    // Constructor to initialize an empty polynomial
    Polynomial() {
        head = NULL;
    }

    // Method to add a node to the polynomial, combining like terms
    void addNode(Node* newNode) {
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            Node* prev = NULL;

            // Traverse to find the right place or a term with the same power
            while (temp != NULL && temp->pow > newNode->pow) {
                prev = temp;
                temp = temp->next;
            }

            // If a term with the same power exists, combine the coefficients
            if (temp != NULL && temp->pow == newNode->pow) {
                temp->coeff += newNode->coeff;
                delete newNode; // Delete the new node since we merged it
            } else {
                // Insert the new node in the correct position
                newNode->next = temp;
                if (prev == NULL) {
                    head = newNode; // Insert at head if prev is NULL
                } else {
                    prev->next = newNode;
                }
            }
        }
    }

    // Method to read a polynomial
    void readPolynomial(int terms) {
        for (int i = 1; i <= terms; ++i) { // Start from 1 for term numbering
            Node* newNode = new Node();
            newNode->read(i); // Pass the term number to read
            addNode(newNode);
        }
    }

    // Method to display the polynomial
    void displayPolynomial() {
        Node* temp = head;
        bool isFirst = true;
        while (temp != NULL) {
            if (!isFirst && temp->coeff > 0) {
                cout << " + ";
            }
            temp->display();
            temp = temp->next;
            isFirst = false;
        }
        cout << endl;
    }

    // Friend function to add two polynomials
    friend void addPolynomial(Polynomial p1, Polynomial p2);
};

// Function to add two polynomials
void addPolynomial(Polynomial p1, Polynomial p2) {
    Polynomial result;
    Node* p1Head = p1.head;
    Node* p2Head = p2.head;

    // Traverse both lists and add terms to the result
    while (p1Head != NULL && p2Head != NULL) {
        if (p1Head->pow == p2Head->pow) {
            Node* newNode = new Node();
            newNode->coeff = p1Head->coeff + p2Head->coeff;
            newNode->pow = p1Head->pow;
            result.addNode(newNode);
            p1Head = p1Head->next;
            p2Head = p2Head->next;
        } else if (p1Head->pow > p2Head->pow) {
            Node* newNode = new Node();
            newNode->coeff = p1Head->coeff;
            newNode->pow = p1Head->pow;
            result.addNode(newNode);
            p1Head = p1Head->next;
        } else {
            Node* newNode = new Node();
            newNode->coeff = p2Head->coeff;
            newNode->pow = p2Head->pow;
            result.addNode(newNode);
            p2Head = p2Head->next;
        }
    }

    // Add any remaining terms from p1
    while (p1Head != NULL) {
        Node* newNode = new Node();
        newNode->coeff = p1Head->coeff;
        newNode->pow = p1Head->pow;
        result.addNode(newNode);
        p1Head = p1Head->next;
    }

    // Add any remaining terms from p2
    while (p2Head != NULL) {
        Node* newNode = new Node();
        newNode->coeff = p2Head->coeff;
        newNode->pow = p2Head->pow;
        result.addNode(newNode);
        p2Head = p2Head->next;
    }

    // Display the result polynomial
    cout << "\nResult of addition: ";
    result.displayPolynomial();
}

int main() {
    Polynomial poly1, poly2;
    int terms;

    // Input for the first polynomial
    cout << "Enter the number of terms for the first polynomial: ";
    cin >> terms;
    poly1.readPolynomial(terms);

    // Input for the second polynomial
    cout << "Enter the number of terms for the second polynomial: ";
    cin >> terms;
    poly2.readPolynomial(terms);

    // Displaying the polynomials
    cout << "\nPolynomial 1: ";
    poly1.displayPolynomial();
    cout << "Polynomial 2: ";
    poly2.displayPolynomial();

    // Adding the polynomials
    addPolynomial(poly1, poly2);

    return 0;
}
