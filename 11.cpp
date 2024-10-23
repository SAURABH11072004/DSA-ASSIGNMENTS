#include<iostream>
#define SIZE 10
using namespace std;

class Employee {
    int ID;
    string name;
    int salary;
public:
    void read() {
        cout << "Enter the Employee ID: ";
        cin >> ID;
        cout << "Enter the Employee Name: ";
        cin >> name;
        cout << "Enter the Employee Salary: ";
        cin >> salary;
    }

    void displayRow() {
        // Convert name to lowercase
        string lowerName = name;
        for (int i = 0; i < lowerName.length(); i++) {
            lowerName[i] = tolower(lowerName[i]);
        }

        // Display the employee details with manual spacing
        cout << "| " << ID;
        if (ID < 10) cout << "     ";   // Adjust space for single digit IDs
        else if (ID < 100) cout << "    "; // Adjust space for two-digit IDs
        else cout << "   ";               // Adjust space for three-digit IDs

        cout << "| " << lowerName;
        for (int i = lowerName.length(); i < 15; i++) {
            cout << " ";  // Add spaces to align name
        }

        cout << "| " << salary;
        if (salary < 10000) cout << "    "; // Adjust space for salary
        else if (salary < 100000) cout << "   ";
        else cout << "  ";
        cout << "|";
    }

    int getID() {
        return ID;
    }
};

class HashTable {
    Employee HT[SIZE];  // Hash table to store employees
    int flag[SIZE];     // Flag to check if a position is occupied
public:
    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            flag[i] = 0;  // Initialize all flags to 0 (empty)
        }
    }

    void insert() {
        Employee newR;
        newR.read();
        int ID = newR.getID();
        int pos = ID % SIZE;

        // Linear probing to handle collisions
        if (flag[pos] == 0) {
            HT[pos] = newR;
            flag[pos] = 1;
        } else {
            // Handle collision using linear probing
            int i = pos;
            do {
                i = (i + 1) % SIZE;
            } while (flag[i] == 1 && i != pos);

            if (i == pos) {
                cout << "Hash table is full, cannot insert employee.\n";
            } else {
                HT[i] = newR;
                flag[i] = 1;
            }
        }
    }

    void displayTable() {
        // Header
        cout << "\nHash Table Contents:\n";
        cout << "+-------+-----------------+---------+------+\n";
        cout << "|  ID   |      Name        | Salary  | Flag |\n";
        cout << "+-------+-----------------+---------+------+\n";
        // Display the contents
        for (int i = 0; i < SIZE; i++) {
            if (flag[i] == 1) {
                HT[i].displayRow();
                cout << " " << flag[i] << " |\n";
            } else {
                // Display empty rows
                cout << "| -     | -               | -       | 0    |\n";
            }
        }
        cout << "+-------+-----------------+---------+------+\n";
    }
};

int main() {
    HashTable table;
    char choice;
    do {
        table.insert();
        cout << "Do you want to add another employee? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    // Display the hash table at the end
    table.displayTable();

    return 0;
}
