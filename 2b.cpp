#include <iostream>
using namespace std;

class employee {
    int emp_id;
    string emp_name;
    int salary;

public:
    // Function to get employee details
    void get() {
        cout << "Enter employee ID: ";
        cin >> emp_id;
        cout << "Enter employee name: ";
        cin >> emp_name;
        cout << "Enter salary: ";
        cin >> salary;
    }

    // Function to display employee details
    void display() {
        cout << "EMP-ID: " << emp_id << endl;
        cout << "EMP-NAME: " << emp_name << endl;
        cout << "SALARY: " << salary << endl;
    }

    // Merge function for Merge Sort
    void merge(employee arr[], int low, int mid, int high) {
        int i = low;
        int j = mid + 1;
        int k = 0;
        employee b[high - low + 1]; // Temporary array to hold sorted employees

        while (i <= mid && j <= high) {
            if (arr[i].emp_name <= arr[j].emp_name) {
                b[k] = arr[i];
                i++;
            } else {
                b[k] = arr[j];
                j++;
            }
            k++;
        }

        while (i <= mid) {
            b[k] = arr[i];
            i++;
            k++;
        }

        while (j <= high) {
            b[k] = arr[j];
            j++;
            k++;
        }

        for (int i = low; i <= high; i++) {
            arr[i] = b[i - low];
        }
    }

    // Merge Sort function to sort employees based on emp_name
    void mergeSort(employee arr[], int low, int high) {
        if (low < high) {
            int mid = (low + high) / 2;
            mergeSort(arr, low, mid);
            mergeSort(arr, mid + 1, high);
            merge(arr, low, mid, high);
        }
    }
};

int main() {
    int n;  // Number of employees
    cout << "Enter the number of employees: ";
    cin >> n;

    employee employees[n];  // Array to store employee objects
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add employee details\n";
        cout << "2. Display employee details\n";
        cout << "3. Sort employees by Employee Name\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Add employee details
                for (int i = 0; i < n; i++) {
                    cout << "\nEntering details for employee " << i + 1 << ":\n";
                    employees[i].get();
                }
                break;

            case 2:
                // Display employee details
                
                    cout << "\nEmployee Details:\n";
                    for (int i = 0; i < n; i++) {
                        employees[i].display();
                        cout << endl;
                    
                } 
                break;

            case 3:
                // Sort employees by Employee Name
                if (n > 0) {  // Check if there are any employees to sort
                    employee obj;
                    obj.mergeSort(employees, 0, n - 1);
                    cout << "\nEmployees sorted by Employee Name:\n";
                    for (int i = 0; i < n; i++) {
                        employees[i].display();  // Display sorted employee details
                        cout << endl;
                    }
                } else {
                    cout << "No employee details to sort.\n";
                }
                break;

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
