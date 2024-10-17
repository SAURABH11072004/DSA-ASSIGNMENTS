#include <iostream>
#include <string>
using namespace std;

class dequeue; // Forward declaration

class Job {
private:
    string jobName;
    int jobTime;    // Job time in minutes
    int jobPriority; // Job priority

public:
    Job* next; // Pointer to the next job
    Job* prev; // Pointer to the previous job

    Job() { // Default constructor
        next = nullptr; // Initialize next to nullptr
        prev = nullptr; // Initialize prev to nullptr
    }

    void read() {
        cout << "Enter job name: ";
        cin >> jobName;
        cout << "Enter job time: ";
        cin >> jobTime; // Read job time as an integer
        cout << "Enter job priority (integer): ";
        cin >> jobPriority; // Read job priority
    }

    void display()  {
        cout << "Job: " << jobName << ", Time: " << jobTime << " minutes, Priority: " << jobPriority << endl;
    }

    friend class JobScheduler; // Grant JobScheduler access to private members
};

class dequeue {
public:
    Job* front; // Front of the queue
    Job* back;  // Back of the queue

    dequeue() { // Constructor
        front = nullptr; // Initialize front to nullptr
        back = nullptr;  // Initialize back to nullptr
    }

    ~ dequeue() {
        while (front) {
            Job* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void addJobToFront() {
        Job* newJob = new Job(); // Create a new job
        newJob->read(); // Read job details

        if (!front) { // If the queue is empty
            front = back = newJob; // Set both front and back to new job
        } else {
            newJob->next = front; // Link new job to current front
            front->prev = newJob; // Link current front back to new job
            front = newJob; // Update front to new job
        }
        cout << "Job added to front successfully.\n";
    }

    void addJobToBack() {
        Job* newJob = new Job(); // Create a new job
        newJob->read(); // Read job details

        if (!back) { // If the queue is empty
            front = back = newJob; // Set both front and back to new job
        } else {
            back->next = newJob; // Link current back to new job
            newJob->prev = back; // Link new job back to current back
            back = newJob; // Update back to new job
        }
        cout << "Job added to back successfully.\n";
    }

    void removeJobFromFront() {
        if (!front) {
            cout << "No jobs to remove from front.\n";
            return;
        }
        Job* temp = front;
        front = front->next; // Move front pointer to the next job
        if (front) front->prev = nullptr; // Update previous pointer of new front
        else back = nullptr; // If queue is now empty, update back
        delete temp; // Delete old front job
        cout << "Job removed from front successfully.\n";
    }

    void removeJobFromBack() {
        if (!back) {
            cout << "No jobs to remove from back.\n";
            return;
        }
        Job* temp = back;
        back = back->prev; // Move back pointer to the previous job
        if (back) back->next = nullptr; // Update next pointer of new back
        else front = nullptr; // If queue is now empty, update front
        delete temp; // Delete old back job
        cout << "Job removed from back successfully.\n";
    }

    void displayJobs() const {
        if (!front) {
            cout << "No jobs in the queue.\n";
            return;
        }
        cout << "Current jobs in the queue:\n";
        Job* current = front;
        while (current) {
            current->display(); // Display job details
            current = current->next;
        }
    }
};

int main() {
    dequeue scheduler;
    int choice;

    do {
        cout << "\nJob Scheduling System\n";
        cout << "1. Add Job to Front\n";
        cout << "2. Add Job to Back\n";
        cout << "3. Remove Job from Front\n";
        cout << "4. Remove Job from Back\n";
        cout << "5. Display Jobs\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                scheduler.addJobToFront();
                break;
            case 2:
                scheduler.addJobToBack();
                break;
            case 3:
                scheduler.removeJobFromFront();
                break;
            case 4:
                scheduler.removeJobFromBack();
                break;
            case 5:
                scheduler.displayJobs();
                break;
            case 6:
                cout << "Exiting the system.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
