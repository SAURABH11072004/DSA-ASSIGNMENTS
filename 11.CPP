#include <iostream>   
#include <string>     
#include <iomanip>    // For formatted output using setw and other manipulators
using namespace std;

#define INITIAL_SIZE 10   // Initial size of the hash table

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
        cin.ignore();   // To ignore the newline character in the input buffer
        getline(cin, name);
        cout << "Enter the Employee Salary: ";
        cin >> salary;
        isOccupied = true;   // Mark slot as occupied after input
    }

    // Displays employee details
    void display() {
        cout << setw(15) << ID << setw(15) << name << setw(10) << salary;
        // Display chain index if it exists, else display "-"
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
    Employee* HT;           // Array to hold employees
    int currentSize;        // Current number of entries in the hash table
    int tableSize;          // Maximum number of slots in the hash table
    const float LOAD_FACTOR = 0.5;   // Threshold for triggering rehashing

    // Hash function to compute hash index based on employee ID
    int hashFunction(int key) {
        return key % tableSize;
    }

    // Rehash function to resize the hash table when load factor exceeds the threshold
    void rehash() {
        cout << "Rehashing in progress...\n";
        int oldSize = tableSize;
        tableSize *= 2;    // Double the size of the table
        Employee* oldHT = HT;   // Store the old table
        HT = new Employee[tableSize];   // Create a new table with updated size
        currentSize = 0;   // Reset the current size

        // Reinsert all valid employees from old table into the new table
        for (int i = 0; i < oldSize; i++) {
            if (oldHT[i].isOccupied) {
                insert(oldHT[i]);  // Insert each occupied employee slot
            }
        }

        delete[] oldHT;   // Free the memory of the old table
    }

    // Insert an employee into the hash table, handling collisions with chaining
    void insert(Employee& newEmployee) {
        int ID = newEmployee.getID();
        int pos = hashFunction(ID);

        // Use linear probing to find an available spot in case of a collision
        int i = 0;
        int prevPos = -1;
        while (HT[(pos + i) % tableSize].isOccupied) {
            prevPos = (pos + i) % tableSize;  // Store last occupied position
            i++;
            if (i == tableSize) {   // Table is full, cannot insert
                cout << "Error: Table is full, unable to insert employee.\n";
                return;
            }
        }

        int finalPos = (pos + i) % tableSize;   // Final position for new employee
        HT[finalPos] = newEmployee;

        // Update chain index for previous position if there was a collision
        if (prevPos != -1) {
            HT[prevPos].chainIndex = finalPos;
        }

        currentSize++;

        // Trigger rehashing if load factor threshold is exceeded
        if (currentSize > LOAD_FACTOR * tableSize) {
            rehash();
        }
    }

public:
    // Constructor initializes the hash table with a given size
    HashTable(int size = INITIAL_SIZE) : tableSize(size), currentSize(0) {
        HT = new Employee[tableSize];
    }

    // Destructor to free memory allocated to the hash table
    ~HashTable() {
        delete[] HT;
    }

    // Insert function to add a new employee to the hash table
    void insert() {
        Employee newEmployee;
        newEmployee.read();
        insert(newEmployee);
    }

    // Display function to print out the entire hash table with chaining index
    void display() {
        cout << setw(10) << "Hash Index" << setw(15) << "Employee ID" << setw(15) << "Name"
             << setw(10) << "Salary" << setw(15) << "Chaining Index" << endl;
        cout << "-------------------------------------------------------------------------" << endl;

        // Loop through the table and display each employee record
        for (int i = 0; i < tableSize; i++) {
            cout << setw(10) << i;
            if (!HT[i].isOccupied) {
                // Display placeholder if the slot is empty
                cout << setw(15) << "-" << setw(15) << "-" << setw(10) << "-" << setw(15) << "-" << endl;
            } else {
                HT[i].display();
            }
        }
    }

    // Search function to find an employee by ID, using linear probing
    void search(int searchID) {
        int pos = hashFunction(searchID);   // Initial position based on hash
        int i = 0;

        // Search until the slot is unoccupied or the employee is found
        while (HT[(pos + i) % tableSize].isOccupied) {
            if (HT[(pos + i) % tableSize].getID() == searchID) {
                cout << "Employee found at location " << (pos + i) % tableSize << endl;
                return;
            }
            i++;
            if (i == tableSize) {   // Break if the entire table has been searched
                break;
            }
        }
        cout << "Employee with ID " << searchID << " not found." << endl;
    }
};

int main() {
    HashTable ht;   // Create hash table object
    int choice, searchID;

    // Display menu options until the user exits
    do {
        cout << "\n1. Insert Employee\n2. Display Hash Table\n3. Search Employee by ID\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            ht.insert();   // Insert employee details
            break;
        case 2:
            ht.display();  // Display entire hash table
            break;
        case 3:
            cout << "Enter Employee ID to search: ";
            cin >> searchID;
            ht.search(searchID);  // Search employee by ID
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



