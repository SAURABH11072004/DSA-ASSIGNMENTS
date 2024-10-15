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

    // Function to sort students based on name using Shell sort
    void shell(student a[], int n) {
        for (int gap = n / 2; gap > 0; gap = gap / 2) {
            for (int i = gap; i < n; i++) {
                student temp = a[i];
                int j = i - gap;
                while (j >= 0 && a[j].name > temp.name) {
                    a[j + gap] = a[j];
                    j = j - gap;
                }
                a[j + gap] = temp;
            }
        }
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    student students[n];  // Array of student objects
    student obj;  // Temporary object to call the sorting function
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enter student details\n";
        cout << "2. Display student details\n";
        cout << "3. Sort students by name\n";
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
                // Sort students by name using Shell sort
                obj.shell(students, n);
                cout << "\nStudents sorted by name:\n";
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
