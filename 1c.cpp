#include<iostream>
using namespace std;

class student {
    int roll;
    string name;
    float cgpa;

public:
    // Function to get details of a student
    void get() {
        cout << "Enter roll: ";
        cin >> roll;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter CGPA: ";
        cin >> cgpa;
    }

    // Function to display details of a student
    void display() {
        cout << "ROLL: " << roll << endl;
        cout << "NAME: " << name << endl;
        cout << "CGPA: " << cgpa << endl;
    }

    // Function to get the maximum CGPA
    float getmax(student a[], int n) {
        float max = a[0].cgpa;
        for (int i = 1; i < n; i++) {
            if (a[i].cgpa > max) {
                max = a[i].cgpa;
            }
        }
        return max;
    }

    // Radix sort based on CGPA (for descending order)
    void radix(student a[], int n) {
        float max = getmax(a, n);  // Get the maximum CGPA
        for (int pos = 1; max * 10 / pos > 0; pos *= 10) {  // Scale CGPA by 10 for decimal handling
            countsort(a, n, pos);  // Perform counting sort based on digit at pos
        }
    }

    // Counting sort for radix sort (in descending order)
    void countsort(student a[], int n, int pos) {
        student b[n];  // Temporary array to store sorted result
        int count[10] = {0};

        // Count occurrences of digits in CGPA (scaled to integer)
        for (int i = 0; i < n; i++) {
            count[ int(a[i].cgpa * 10 / pos) % 10 ]++;
        }

        // Modify the count array for descending order
        for (int i = 8; i >= 0; i--) {
            count[i] += count[i + 1];
        }

        // Build the sorted array in descending order
        for (int i = n - 1; i >= 0; i--) {
            int digit = (int(a[i].cgpa * 10 / pos) % 10);
            b[--count[digit]] = a[i];
        }

        // Copy the sorted array back to the original array
        for (int i = 0; i < n; i++) {
            a[i] = b[i];
        }
    }
};

int main() {
    int n, choice;
    cout << "Enter number of students: ";
    cin >> n;

    student students[n];  // Array of student objects
    student obj;  // Object to call sorting functions

    do {
        cout << "\nMenu:\n";
        cout << "1. Enter student details\n";
        cout << "2. Display student details\n";
        cout << "3. Sort students by CGPA using Radix Sort (Topper first)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Enter details for all students
                for (int i = 0; i < n; i++) {
                    cout << "\nEnter details for student " << i + 1 << ":\n";
                    students[i].get();
                }
                break;

            case 2:
                // Display details of all students
                cout << "\nStudent Details:\n";
                for (int i = 0; i < n; i++) {
                    students[i].display();
                    cout << endl;
                }
                break;

            case 3:
                // Sort students by CGPA using Radix sort in descending order
                obj.radix(students, n);
                cout << "\nStudents sorted by CGPA (Topper first):\n";
                for (int i = 0; i < n; i++) {
                    students[i].display();
                    cout << endl;
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
