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
    bool isOccupied; // To mark if a position in the array is occupied
    int chainIndex;  // To store the index where the collision occurred

    Employee() : isOccupied(false), chainIndex(-1) {} // Constructor initializing fields

    void read() {
        cout << "Enter the Employee ID: ";
        cin >> ID;
        cout << "Enter the Employee Name: ";
        cin >> name;
        cout << "Enter the Employee Salary: ";
        cin >> salary;
        isOccupied = true; // Mark this employee as active
    }

    void display() {
        cout << setw(15) << ID << setw(15) << name << setw(10) << salary;
        if (chainIndex != -1) {
            cout << setw(15) << chainIndex << endl;
        } else {
            cout << setw(15) << "-" << endl;
        }
    }

    int getID() {
        return ID;
    }
};

class HashTable {
    Employee HT[SIZE]; // Array of Employee objects for storing employee data

public:
    HashTable() {
        // Initialize hash table with unoccupied employees
        for (int i = 0; i < SIZE; i++) {
            HT[i].isOccupied = false;
        }
    }

    // Insert employee using linear probing for collision resolution
    void insert() {
        Employee newEmployee;
        newEmployee.read();
        int ID = newEmployee.getID();
        int pos = ID % SIZE; // Hash function

        // Linear probing: find the next available spot if there's a collision
        int i = 0;
        while (HT[(pos + i) % SIZE].isOccupied) {
            i++;
            if (i == SIZE) {
                cout << "Hash table is full. Cannot insert employee.\n";
                return;
            }
        }

        int finalPos = (pos + i) % SIZE;
        HT[finalPos] = newEmployee;
        if (i != 0) {
            HT[finalPos].chainIndex = pos; // Store original position for chaining
        }
    }

    // Display the entire hash table in table format with chaining index
    void display() {
        cout << setw(10) << "Hash Index" << setw(15) << "Employee ID" << setw(15) << "Name" << setw(10) << "Salary" << setw(15) << "Chaining Index" << endl;
        cout << "-------------------------------------------------------------------------" << endl;

        for (int i = 0; i < SIZE; i++) {
            cout << setw(10) << i; // Print hash index
            if (!HT[i].isOccupied) {
                // If no employee exists at the hash index, print "-"
                cout << setw(15) << "-" << setw(15) << "-" << setw(10) << "-" << setw(15) << "-" << endl;
            } else {
                // Display the employee details along with the chaining index
                HT[i].display();
            }
        }
    }

    // Searching for an employee by ID using linear probing
    void search(int searchID) {
        int pos = searchID % SIZE;
        int i = 0;

        // Linear probing: search through the table
        while (HT[(pos + i) % SIZE].isOccupied) {
            if (HT[(pos + i) % SIZE].getID() == searchID) {
                cout << "Employee found at hash index " << (pos + i) % SIZE << ": ";
                HT[(pos + i) % SIZE].display();
                return;
            }
            i++;
            if (i == SIZE) {
                break; // If searched through the entire table, exit loop
            }
        }

        cout << "Employee with ID " << searchID << " not found." << endl;
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
