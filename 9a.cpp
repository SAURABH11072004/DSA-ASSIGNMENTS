#include <iostream>
using namespace std;

class party {
    string name;
    int mo_no;

public:
    party* next;  // Pointer to the next party in the queue

    // Function to read customer details
    void read() {
        cout << "Enter customer name: ";
        cin >> name;
        cout << "Enter customer mobile number: ";
        cin >> mo_no;
    }

    // Function to display customer details
    void display() {
        cout << "Customer name: " << name << "\n";
        cout << "Customer mobile number: " << mo_no << "\n";
    }
};

// Queue class to manage the waitlist
class Queue {
    party* front;
    party* rear;

public:
    // Constructor to initialize an empty queue
    Queue() {
        front = rear = nullptr;
    }

    // Function to add a new party to the waitlist
    void add_to_party() {
        party* nn = new party;  // Create a new node (party)
        nn->read();             // Get customer details
        nn->next = nullptr;     // New node's next should be null (as it's the last node)

        if (rear == nullptr) {  // If the queue is empty
            front = rear = nn;  // Both front and rear will point to the new node
        } else {
            rear->next = nn;    // Link the new node at the end of the queue
            rear = nn;          // Update the rear to point to the new node
        }

        cout << "Party added to the waitlist.\n";
    }

    // Function to seat (remove) the party at the front of the waitlist
    void seat_party() {
        if (front == nullptr) {  // If the queue is empty
            cout << "No parties in the waitlist.\n";
            return;
        }

        party* temp = front;     // Store the front node
        cout << "Seating the following party:\n";
        temp->display();         // Display the details of the party being seated

        front = front->next;     // Move front to the next party in the queue

        if (front == nullptr) {  // If the queue becomes empty after seating
            rear = nullptr;      // Rear should also be set to null
        }

        delete temp;             // Free memory of the seated party
    }

    // Function to display the current waitlist
    void display_waitlist() {
        if (front == nullptr) {  // If the queue is empty
            cout << "Waitlist is empty.\n";
            return;
        }

        party* current = front;
        cout << "Current waitlist:\n";
        while (current != nullptr) {  // Traverse and display each party in the queue
            current->display();
            current = current->next;
        }
    }

    // Destructor to free all remaining nodes in the queue
    ~Queue() {
        while (front != nullptr) {
            party* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    Queue aa;
    int choice;

    do {
        cout << "\nRestaurant Waitlist System\n";
        cout << "1. Add Party to Waitlist\n";
        cout << "2. Seat Party\n";
        cout << "3. Display Waitlist\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                aa.add_to_party();
                break;
            case 2:
                aa.seat_party();
                break;
            case 3:
                aa.display_waitlist();
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
