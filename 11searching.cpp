#include <iostream>
#include <string>
#include <iomanip> // For using setw() to align columns
using namespace std;

#define SIZE 10

class Employee {
public:
    int ID;
    string name;
    int salary;
    Employee* next; // Pointer to the next employee for chaining

    Employee() : next(nullptr) {} // Constructor initializing next as nullptr

    void read() {
        cout << "Enter the Employee ID: ";
        cin >> ID;
        cout << "Enter the Employee Name: ";
        cin >> name;
        cout << "Enter the Employee Salary: ";
        cin >> salary;
    }

    void display() {
        cout << setw(10) << ID << setw(15) << name << setw(10) << salary << endl;
    }

    int getID() {
        return ID;
    }
};

class HashTable {
    Employee* HT[SIZE]; // Array of pointers to Employee objects (for chaining)

public:
    HashTable() {
        // Initialize hash table with null pointers
        for (int i = 0; i < SIZE; i++) {
            HT[i] = nullptr;
        }
    }

    // Insert employee using chaining
    void insert() {
        Employee* newR = new Employee();
        newR->read();
        int ID = newR->getID();
        int pos = ID % SIZE; // Hash function

        // Insert employee at the head of the chain (linked list) at position 'pos'
        if (HT[pos] == nullptr) {
            HT[pos] = newR;
        } else {
            // Collision: insert new employee at the beginning of the linked list
            newR->next = HT[pos];
            HT[pos] = newR;
        }
    }

    // Display the entire hash table in table format
    void display() {
        cout << setw(10) << "Hash Index" << setw(15) << "Employee ID" << setw(15) << "Name" << setw(10) << "Salary" << endl;
        cout << "-------------------------------------------------------------" << endl;

        for (int i = 0; i < SIZE; i++) {
            cout << setw(10) << i << setw(15);
            if (HT[i] == nullptr) {
                // If no employee exists at the hash index, print "-"
                cout << setw(15) << "-" << setw(15) << "-" << setw(10) << "-" << endl;
            } else {
                // Display all employees at this hash index
                Employee* temp = HT[i];
                while (temp != nullptr) {
                    cout << setw(10) << temp->ID << setw(15) << temp->name << setw(10) << temp->salary << endl;
                    temp = temp->next;
                    if (temp != nullptr) {
                        cout << setw(10) << " "; // Adding extra spacing for additional employees in the same hash index
                    }
                }
            }
        }
    }

    // Searching for an employee by ID
    void search(int searchID) {
        int pos = searchID % SIZE;
        Employee* temp = HT[pos];
        bool found = false;

        while (temp != nullptr) {
            if (temp->getID() == searchID) {
                cout << "Employee found at hash index " << pos << ": ";
                temp->display();
                found = true;
                break;
            }
            temp = temp->next;
        }

        if (!found) {
            cout << "Employee with ID " << searchID << " not found." << endl;
        }
    }
};

int main() {
    HashTable ht;
    int choice, searchID;

    do {
        cout << "\n1. Insert Employee\n2. Display Hash Table\n3. Search Employee by ID\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            ht.insert();
            break;
        case 2:
            ht.display();
            break;
        case 3:
            cout << "Enter Employee ID to search: ";
            cin >> searchID;
            ht.search(searchID);
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
