#include <iostream>
#include <string>

using namespace std;

// Node class for the doubly linked list
class Node {
private:
    string text; // Text content

public:
    Node* prev; // Pointer to the previous node
    Node* next; // Pointer to the next node

    // Constructor to initialize the node
    Node() {
        prev = nullptr;
        next = nullptr;
    }

    // Method to get the text data from user input
    void getData() {
        cout << "Enter text: ";
        getline(cin, text); // Get the entire line of text including spaces
    }

    // Method to display the text
    void display() {
        cout << text; // Display the text content
    }

    // Method to get the text data
    string getText() {
        return text; // Return the text content
    }
};

// TextEditor class to manage the text buffer
class TextEditor {
private:
    Node* head; // Pointer to the head of the linked list

public:
    // Constructor
    TextEditor() {
        head = nullptr;
    }

    // Function to insert text
    void insertText() {
        Node* newNode = new Node; // Create a new node
        newNode->getData();         // Get text input from user
        if (head == nullptr) {      // If the list is empty
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
        cout << "Inserted: " << newNode->getText() << endl;
    }

    // Function to display all text
    void displayAllText() {
        if (head == nullptr) {
            cout << "No text" << endl;
            return;
        }
        cout << "---- Text Editor ----" << endl;
        Node* temp = head;
        int index = 1; // Initialize index for numbering
        while (temp != nullptr) {
            cout << "Text " << index << ": "; // Display the text number
            temp->display(); // Use the display method of the Node class
            cout << endl; // New line after each text
            temp = temp->next;
            index++; // Increment index
        }
    }

    // Function to delete text
    void deleteText(string& text) {
        if (head == nullptr) {
            cout << "No text" << endl;
            return;
        }
        if (head->getText() == text) {
            Node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
            cout << "Text deleted." << endl;
            return;
        }
        Node* current = head;
        Node* prev = nullptr;
        while (current != nullptr && current->getText() != text) {
            prev = current;
            current = current->next;
        }
        if (current != nullptr) {
            prev->next = current->next;
            if (current->next != nullptr) {
                current->next->prev = prev;
            }
            delete current;
            cout << "Text removed" << endl;
        } else {
            cout << "Text not found" << endl;
        }
    }

    // Function to search for text
    void searchText(string& text) {
        if (head == nullptr) {
            cout << "No text" << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->getText() == text) {
                cout << "Found: " << text << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Text not found: " << text << endl;
    }

    // Function to print text in reverse
    void printReverse() {
        if (head == nullptr) {
            cout << "No text to reverse." << endl;
            return;
        }
        cout << "Text in Reverse:" << endl;
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        while (temp != nullptr) {
            temp->display();
            cout << endl;
            temp = temp->prev;
        }
    }

    // Destructor to clean up memory
    ~TextEditor() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    TextEditor editor;
    int choice;
    string text;

    do {
        cout << "\nSimple Text Editor" << endl;
        cout << "1. Insert Text" << endl;
        cout << "2. Delete Text" << endl;
        cout << "3. Display All Text" << endl;
        cout << "4. Search Text" << endl;
        cout << "5. Print Text in Reverse" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore leftover newline character

        switch (choice) {
            case 1:
                editor.insertText();
                break;
            case 2:
                cout << "Enter text to delete: ";
                getline(cin, text); // Use getline to accept text with spaces
                editor.deleteText(text);
                break;
            case 3:
                editor.displayAllText();
                break;
            case 4:
                cout << "Enter text to search: ";
                getline(cin, text); // Use getline to accept text with spaces
                editor.searchText(text);
                break;
            case 5:
                editor.printReverse();
                break;
            case 6:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
