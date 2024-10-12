#include <iostream>
#include <string>
using namespace std;

// Employee class to hold employee data and operations
class Employee {
private:
    int emp_id;              // Employee ID
    string emp_name;         // Employee Name
    float emp_salary;        // Employee Salary

public:
    // Constructor to initialize employee data with default values
    Employee(int a = 0, string b = "", float salary = 0.0f) {
        emp_id = a;          // Initialize emp_id
        emp_name = b;       // Initialize emp_name
        emp_salary = salary; // Initialize emp_salary
    }

    // Method to display employee details
    void displayEmployee() const {
        cout << "EMP-ID: " << emp_id << ", Name: " << emp_name << ", Salary: " << emp_salary << endl;
    }

    // Accessor methods to get employee details
    int getEmpID() const { return emp_id; }   // Get Employee ID
    string getEmpName() const { return emp_name; } // Get Employee Name

    // Swap function to exchange two Employee objects
    void swap(Employee& a, Employee& b) {
        Employee temp = a; // Temporary variable to hold one Employee
        a = b;             // Swap a with b
        b = temp;         // Assign temp to b
    }

    // Partition function for Quick Sort (sorting by EMP-ID)
    int partition(Employee employees[], int low, int high) {
        int pivot = employees[low].getEmpID(); // Pivot as first element
        int i = low + 1;                       // Index for left side
        int j = high;                          // Index for right side

        // Rearranging employees based on the pivot
        while (i <= j) {
            while (i <= high && employees[i].getEmpID() <= pivot) {
                i++; // Move right if current ID is less than or equal to pivot
            }
            while (j >= low && employees[j].getEmpID() > pivot) {
                j--; // Move left if current ID is greater than pivot
            }
            if (i < j) {
                swap(employees[i], employees[j]); // Swap if indices are in the correct order
            }
        }
        swap(employees[low], employees[j]); // Place pivot in the correct position
        return j; // Return pivot index
    }

    // Quick Sort function for sorting by EMP-ID
    void quickSortByID(Employee employees[], int low, int high) {
        if (low < high) {
            int j = partition(employees, low, high); // Partition and get pivot index
            quickSortByID(employees, low, j - 1);     // Recursively sort left half
            quickSortByID(employees, j + 1, high);    // Recursively sort right half
        }
    }

    // Merge function for Merge Sort (sorting by EMP-Name)
    void merge(Employee employees[], int low, int mid, int high) {
        int i = low;                     // Index for left subarray
        int j = mid + 1;                // Index for right subarray
        int k = low;                    // Index for temporary array
        Employee temp[20];              // Temporary array for merging

        // Merge the two halves
        while (i <= mid && j <= high) {
            if (employees[i].getEmpName() <= employees[j].getEmpName()) {
                temp[k] = employees[i]; // Add from left half if smaller
                i++;
            } else {
                temp[k] = employees[j]; // Add from right half if smaller
                j++;
            }
            k++; // Move to next position in temp array
        }

        // Copy remaining elements from the left half
        while (i <= mid) {
            temp[k] = employees[i]; // Copy remaining left elements
            i++;
            k++;
        }

        // Copy remaining elements from the right half
        while (j <= high) {
            temp[k] = employees[j]; // Copy remaining right elements
            j++;
            k++;
        }

        // Copy the merged elements back to the original array
        for (i = low; i <= high; i++) {
            employees[i] = temp[i]; // Update original array
        }
    }

    // Merge Sort function for sorting by EMP-Name
    void mergeSortByName(Employee employees[], int low, int high) {
        if (low < high) {
            int mid = (low + high) / 2;             // Find the midpoint
            mergeSortByName(employees, low, mid);   // Recursively sort left half
            mergeSortByName(employees, mid + 1, high); // Recursively sort right half
            merge(employees, low, mid, high);       // Merge the two halves
        }
    }
};

// Main program with menu-driven system
int main() {
    Employee employees[20] = { // Initialize an array of Employee objects
        Employee(105, "Saurabh", 85000),
        Employee(101, "Nilesh", 75000),
        Employee(109, "Ashwa", 72000),
        Employee(103, "Nelay", 65000),
        Employee(104, "Yash", 89000),
        Employee(110, "Raj", 67000),
        Employee(102, "Isha", 77000),
        Employee(108, "Aniket", 82000),
        Employee(107, "Gaurav", 90000),
        Employee(106, "Pranav", 78000),
        Employee(111, "Pratik", 93000),
        Employee(113, "Mohit", 67000),
        Employee(112, "Rakesh", 92000),
        Employee(114, "Arjun", 70000),
        Employee(116, "Devendra", 88000),
        Employee(118, "Kiran", 95000),
        Employee(115, "Anil", 69000),
        Employee(120, "Vishal", 98000),
        Employee(119, "Rahul", 72000),
        Employee(117, "Sagar", 81000)
    };

    int employeeCount = 20; // Total number of employees
    int choice;            // User choice for menu

    // Menu-driven loop
    do {
        cout << "\n--- Employee Database Menu ---\n";
        cout << "1. Display all Employees\n";
        cout << "2. Sort Employees by EMP-ID (Quick Sort)\n";
        cout << "3. Sort Employees Alphabetically by Name (Merge Sort)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\n--- Employee List ---\n";
                for (int i = 0; i < employeeCount; i++) {
                    employees[i].displayEmployee(); // Display each employee's details
                }
                break;

            case 2:
                employees[0].quickSortByID(employees, 0, employeeCount - 1); // Sort by EMP-ID
                cout << "\n--- Sorted by EMP-ID (Quick Sort) ---\n";
                for (int i = 0; i < employeeCount; i++) {
                    employees[i].displayEmployee(); // Display sorted employee details
                }
                break;

            case 3:
                employees[0].mergeSortByName(employees, 0, employeeCount - 1); // Sort by EMP-Name
                cout << "\n--- Sorted Alphabetically by Name (Merge Sort) ---\n";
                for (int i = 0; i < employeeCount; i++) {
                    employees[i].displayEmployee(); // Display sorted employee details
                }
                break;

            case 4:
                cout << "Exiting...\n"; // Exit the program
                break;

            default:
                cout << "Invalid choice! Please try again.\n"; // Handle invalid choice
        }
    } while (choice != 4); // Continue until the user chooses to exit

    return 0; // End of the program
}
