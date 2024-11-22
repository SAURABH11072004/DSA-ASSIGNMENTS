#include <iostream>
#include <string>
#include <iomanip> // For formatted output using setw and other manipulators
using namespace std;

#define TABLE_SIZE 10 // Fixed size of the hash table

// Employee class to hold individual employee data
class Employee {
public:
    int ID;                // Employee ID
    string name;           // Employee name
    int salary;            // Employee salary
    bool isOccupied;       // Status flag to check if the slot is occupied
    int chainIndex;        // Chain index for resolving collisions

    // Default constructor to initialize attributes
    Employee() : ID(-1), salary(0), isOccupied(false), chainIndex(-1) {}

    // Reads employee data from user input
    void read() {
        cout << "Enter the Employee ID: ";
        cin >> ID;
        cout << "Enter the Employee Name: ";
        cin.ignore(); // To ignore the newline character in the input buffer
        getline(cin, name);
        cout << "Enter the Employee Salary: ";
        cin >> salary;
        isOccupied = true; // Mark slot as occupied after input
    }

    // Displays employee details
    void display() {
        cout << setw(15) << ID << setw(15) << name << setw(10) << salary;
        if (chainIndex != -1) {
            cout << setw(15) << chainIndex << endl;
        } else {
            cout << setw(15) << "-" << endl;
        }
    }

    // Returns the employee ID
    int getID() {
        return ID;
    }
};

// HashTable class to manage a table of Employee records
class HashTable {
    Employee HT[TABLE_SIZE]; // Fixed-size hash table array

    // Hash function to compute hash index based on employee ID
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    // Insert an employee into the hash table
    void insert() {
        Employee newEmployee;
        newEmployee.read();
        int ID = newEmployee.getID();
        int pos = hashFunction(ID);

        // Handle collisions using linear probing
        int i = 0;
        int prevPos = -1;
        while (HT[(pos + i) % TABLE_SIZE].isOccupied) {
            prevPos = (pos + i) % TABLE_SIZE; // Store the last occupied position
            i++;
            if (i == TABLE_SIZE) { // Table is full
                cout << "Error: Table is full, unable to insert employee.\n";
                return;
            }
        }

        int finalPos = (pos + i) % TABLE_SIZE; // Final position for the new employee
        HT[finalPos] = newEmployee;

        // Update chain index for the previous position if there was a collision
        if (prevPos != -1) {
            HT[prevPos].chainIndex = finalPos;
        }

        cout << "Employee inserted successfully.\n";
    }

    // Display the hash table
    void display() {
        cout << setw(10) << "Hash Index" << setw(15) << "Employee ID" << setw(15) << "Name"
             << setw(10) << "Salary" << setw(15) << "Chaining Index" << endl;
        cout << "-------------------------------------------------------------------------" << endl;

        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << setw(10) << i;
            if (!HT[i].isOccupied) {
                // Display placeholder for empty slots
                cout << setw(15) << "-" << setw(15) << "-" << setw(10) << "-" << setw(15) << "-" << endl;
            } else {
                HT[i].display();
            }
        }
    }

    // Search for an employee by ID
    void search(int searchID) {
        int pos = hashFunction(searchID);
        int i = 0;

        // Search until the slot is unoccupied or the employee is found
        while (HT[(pos + i) % TABLE_SIZE].isOccupied) {
            if (HT[(pos + i) % TABLE_SIZE].getID() == searchID) {
                cout << "Employee found at location " << (pos + i) % TABLE_SIZE << endl;
                return;
            }
            i++;
            if (i == TABLE_SIZE) { // Entire table has been searched
                break;
            }
        }
        cout << "Employee with ID " << searchID << " not found.\n";
    }
};

int main() {
    HashTable ht; // Create hash table object
    int choice, searchID;

    // Display menu options until the user exits
    do {
        cout << "\n1. Insert Employee\n2. Display Hash Table\n3. Search Employee by ID\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            ht.insert(); // Insert employee details
            break;
        case 2:
            ht.display(); // Display the hash table
            break;
        case 3:
            cout << "Enter Employee ID to search: ";
            cin >> searchID;
            ht.search(searchID); // Search employee by ID
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
