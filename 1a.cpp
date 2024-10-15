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
        cout << "Roll: " << roll << endl;
        cout << "Name: " << name << endl;
        cout << "CGPA: " << cgpa << endl;
    }

    // Function to sort students based on roll numbers using insertion sort
    void insertion(student a[], int n) {
        for (int i = 1; i < n; i++) {
            student temp = a[i];
            int j = i - 1;
            while (j >= 0 && a[j].roll > temp.roll) {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = temp;
        }
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    student students[n];  // Array of student objects
    student obj;  // Temporary object to call the insertion function
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enter student details\n";
        cout << "2. Display student details\n";
        cout << "3. Sort students by roll number\n";
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
                // Sort students by roll number using the temporary object
                obj.insertion(students, n);
                cout << "\nStudents sorted by roll number:\n";
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
