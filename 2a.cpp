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

    // Partition function for Quick Sort (based on emp_id)
    int partition(employee arr[], int low, int high) {
        int pivot = arr[low].emp_id;  // Pivot is chosen as the emp_id of the first employee
        int i = low, j = high;

        while (i < j) {
            // Increment i while arr[i].emp_id <= pivot
            while (arr[i].emp_id <= pivot && i < high)
                i++;
            // Decrement j while arr[j].emp_id > pivot
            while (arr[j].emp_id > pivot)
                j--;
            // Swap if i is still less than j
            if (i < j)
                swap(arr[i], arr[j]);
        }
        // Swap the pivot element with arr[j]
        swap(arr[low], arr[j]);
        return j;  // Return the partition index
    }

    // Quick Sort function to sort employees based on emp_id
    void quickSort(employee arr[], int low, int high) {
        if (low < high) {
            int pivotIndex = partition(arr, low, high);  // Partition the array
            quickSort(arr, low, pivotIndex - 1);  // Sort the left side of the pivot
            quickSort(arr, pivotIndex + 1, high);  // Sort the right side of the pivot
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
        cout << "3. Sort employees by Employee ID\n";
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
                if (n == 0) {
                    cout << "No employee details available.\n";
                } else {
                    cout << "\nEmployee Details:\n";
                    for (int i = 0; i < n; i++) {
                        employees[i].display();
                        cout << endl;
                    }
                }
                break;

            case 3:
                // Sort employees by Employee ID
                if (n == 0) {
                    cout << "No employee details to sort.\n";
                } else {
                    employee obj;
                    obj.quickSort(employees, 0, n - 1);
                    cout << "\nEmployees sorted by Employee ID:\n";
                    for (int i = 0; i < n; i++) {
                        employees[i].display();  // Display sorted employee details
                        cout << endl;
                    }
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
