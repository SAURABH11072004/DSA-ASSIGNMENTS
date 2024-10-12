#include <iostream> // Include the input-output stream library for console operations
#include <string>   // Include the string library to use the string class
using namespace std; // Use the standard namespace to avoid prefixing with std::

const int MAX_STUDENTS = 15; // Define a constant for the maximum number of students

// Class to hold student data and manage operations
class Student {
private:
    int roll_no;  // Roll number as an integer
    string name;  // Student's name
    float sgpa;   // Student's SGPA (Semester Grade Point Average)

public:
    // Constructor to initialize student data
    Student(int r = 0, const string& n = "", float s = 0.0) {
        roll_no = r; // Set roll number
        name = n;    // Set name
        sgpa = s;    // Set SGPA
    }

    // Method to display student details
    void displayStudent() const {
        cout << "Roll No: " << roll_no << ", Name: " << name << ", SGPA: " << sgpa << endl;
    }

    // Accessor methods to retrieve private member variables
    int getRollNo() const { return roll_no; } // Get roll number
    string getName() const { return name; }   // Get name
    float getSGPA() const { return sgpa; }     // Get SGPA

    // Method for sorting students by roll numbers using Insertion Sort
    void insertionSortByRollNo(Student students[], int count) {
        for (int i = 1; i < count; i++) {
            Student temp = students[i]; // Store the current student
            int j = i - 1; // Start comparing with the previous student
            // Shift elements that are greater than temp to the right
            while (j >= 0 && students[j].getRollNo() > temp.getRollNo()) {
                students[j + 1] = students[j]; // Shift student to the right
                j--; // Move to the previous student
            }
            students[j + 1] = temp; // Place temp in the correct position
        }
    }

    // Method for sorting students by names using Shell Sort
    void shellSortByName(Student students[], int count) {
        // Start with a gap and reduce it each iteration
        for (int gap = count / 2; gap >= 1; gap /= 2) {
            for (int i = gap; i < count; i++) {
                Student temp = students[i]; // Store the current student
                int j = i; // Start j from i
                // Shift elements that are greater than temp to the right
                while (j >= gap && students[j - gap].getName() > temp.getName()) {
                    students[j] = students[j - gap]; // Shift student to the right
                    j -= gap; // Move back by gap
                }
                students[j] = temp; // Place temp in the correct position
            }
        }
    }

    // Method for counting sort by SGPA
    void countingSortBySGPA(Student students[], int count, int pos) {
        Student output[MAX_STUDENTS]; // Output array for sorted students
        int countArray[10] = {0}; // Count array to store count of occurrences of each digit

        // Count occurrences of digits in the specified position
        for (int i = 0; i < count; i++) {
            ++countArray[int(students[i].getSGPA() * 10) / pos % 10]; // Count occurrence of digit
        }

        // Update count array to hold actual positions
        for (int i = 1; i < 10; i++) {
            countArray[i] += countArray[i - 1]; // Cumulative count
        }

        // Build the sorted array
        for (int i = count - 1; i >= 0; i--) {
            int index = int(students[i].getSGPA() * 10) / pos; // Get the current digit
            --countArray[index % 10]; // Decrement the count for this digit
            output[countArray[index % 10]] = students[i]; // Assign the student to the output array
        }

        // Copy sorted elements back to the original array
        for (int i = 0; i < count; i++) {
            students[i] = output[i]; // Copy the sorted output back to students array
        }
    }

    // Method for radix sort by SGPA
    void radixSortBySGPA(Student students[], int count) {
        float maxSGPA = getMaxSGPA(students, count); // Get the maximum SGPA

        // Perform counting sort for each digit
        for (int pos = 1; int(maxSGPA * 10) / pos > 0; pos *= 10) {
            countingSortBySGPA(students, count, pos); // Sort based on current digit position
        }
    }

    // Method to get the maximum SGPA from the students
    float getMaxSGPA(Student students[], int count) {
        float maxSGPA = students[0].getSGPA(); // Assume the first student's SGPA is the maximum
        for (int i = 1; i < count; i++) {
            if (students[i].getSGPA() > maxSGPA) {
                maxSGPA = students[i].getSGPA(); // Update maxSGPA if a higher SGPA is found
            }
        }
        return maxSGPA; // Return the maximum SGPA found
    }

    // Method to display the top N toppers
    void displayTopToppers(Student students[], int count, int topN) {
        radixSortBySGPA(students, count); // Sort students by SGPA
        cout << "Top " << topN << " Toppers:\n"; // Display header
        for (int i = count - 1; i >= count - topN && i >= 0; i--) {
            students[i].displayStudent(); // Display the top N students
        }
    }
};

int main() {
    // Initialize the array of Student objects with data
    Student students[MAX_STUDENTS] = {
        {200, "Saurabh", 9.2},
        {201, "Nilesh", 8.7},
        {202, "Ashwa", 8.9},
        {203, "Nelay", 7.8},
        {204, "Yash", 9.1},
        {205, "Raj", 7.4},
        {206, "Isha", 8.5},
        {207, "Aniket", 7.6},
        {208, "Gaurav", 9.4},
        {209, "Pranav", 8.3},
        {210, "Pratik", 9.0},
        {211, "Mohit", 7.7},
        {212, "Rakesh", 9.5},
        {213, "Arjun", 7.2},
        {214, "Devendra", 9.3}
    };

    int choice; // Variable to store user's menu choice
    int studentCount = MAX_STUDENTS; // Counter for the number of students added

    // Menu-driven loop for user interaction
    do {
        cout << "\n--- Student Database Menu ---\n"; // Display menu header
        cout << "1. Display all students\n"; // Option to display all students
        cout << "2. Sort by Roll Numbers (Insertion Sort)\n"; // Option to sort by roll numbers
        cout << "3. Sort by Names (Shell Sort)\n"; // Option to sort by names
        cout << "4. Display Top 10 Toppers (Radix Sort by SGPA)\n"; // Option to display top 10 students
        cout << "5. Exit\n"; // Option to exit the program
        cout << "Enter your choice: "; // Prompt for user choice
        cin >> choice; // Read user's choice

        switch (choice) {
            case 1: // Case for displaying all students
                cout << "\n--- Student List ---\n"; // Display header
                for (int i = 0; i < studentCount; i++) {
                    students[i].displayStudent(); // Display each student's details
                }
                break;
            case 2: // Case for sorting by roll numbers
                students[0].insertionSortByRollNo(students, studentCount); // Sort students by roll number
                cout << "Students sorted by Roll Numbers:\n"; // Confirmation message
                for (int i = 0; i < studentCount; i++) {
                    students[i].displayStudent(); // Display sorted students
                }
                break;
            case 3: // Case for sorting by names
                students[0].shellSortByName(students, studentCount); // Sort students by name
                cout << "Students sorted by Names:\n"; // Confirmation message
                for (int i = 0; i < studentCount; i++) {
                    students[i].displayStudent(); // Display sorted students
                }
                break;
            case 4: // Case for displaying top 10 toppers
                students[0].displayTopToppers(students, studentCount, 10); // Display top 10 toppers
                break;
            case 5: // Case for exiting the program
                cout << "Exiting program...\n"; // Exit message
                break;
            default: // Case for invalid input
                cout << "Invalid choice. Please try again.\n"; // Error message
        }
    } while (choice != 5); // Continue until the user chooses to exit

    return 0; // End of the program
}
