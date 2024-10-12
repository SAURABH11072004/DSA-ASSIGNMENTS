#include <iostream>
#include <string>
using namespace std;

// Class to represent a Customer with name and contact number
class Customer {
    string customer_name; // Stores the customer's name
    int contact; // Stores the customer's contact number

public:
    
    // Function to read customer details
    void read() {
        cout << "ENTER CUSTOMER NAME: ";
        cin >> customer_name;
        cout << "ENTER CONTACT NO: ";
        cin >> contact;
    }

    // Function to display customer details
    void display() {
        cout << "CUSTOMER NAME: " << customer_name << endl;
        cout << "CUSTOMER CONTACT: " << contact << endl;
    }
};

// Class to represent a Circular Queue for handling customers
class CircularQueue {
    Customer* queue; // Dynamic array to store customers in queue
    int maxsize; // Maximum size of the queue
    int rear, front; // Indices to track the rear and front of the queue

public:
    
    // Constructor to initialize the queue with a given size
    CircularQueue(int size) {
        maxsize = size; // Set maximum queue size
        queue = new Customer[maxsize]; // Dynamically allocate memory for the queue
        front = rear = -1; // Initialize front and rear indices to -1 (empty queue)
    }

    // Function to check if the queue is full
    bool isFull() {
        return (rear + 1) % maxsize == front; // Queue is full if next rear equals front
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (front == -1);  // Queue is empty if front is -1
    }

    // Function to add (enqueue) a customer to the queue
    void add(Customer customer) {
        if (isFull()) { // Check if the queue is full before adding
            cout << "Queue is full! Cannot add more customers." << endl;
        } else {
            if (front == -1) { // If the queue was empty, set front to 0
                front = 0;
            }
            rear = (rear + 1) % maxsize; // Update rear position circularly
            queue[rear] = customer; // Add customer to the queue
            cout << "Customer added to the queue." << endl;
        }
    }

    // Function to remove (dequeue) a customer from the queue
    void remove() {
        if (isEmpty()) { // Check if the queue is empty before removing
            cout << "Queue is empty! No customers to checkout." << endl;
        } else {
            cout << "Customer checking out: ";
            queue[front].display(); // Display the customer who is checking out
            if (front == rear) { // If only one customer is in the queue
                front = rear = -1; // Reset the queue to empty
            } else {
                front = (front + 1) % maxsize; // Update front position circularly
            }
        }
    }

    // Function to display all customers in the queue
    void displayQueue() {
        if (isEmpty()) { // Check if the queue is empty before displaying
            cout << "No customers in the queue." << endl;
        } else {
            cout << "Customers in the queue: " << endl;
            int i = front; // Start from the front of the queue
            while (i != rear) { // Loop through the queue until reaching the rear
                queue[i].display(); // Display each customer
                i = (i + 1) % maxsize; // Update index circularly
            }
            queue[i].display(); // Display the last customer (at rear)
        }
    }

    // Destructor to release the memory allocated for the queue
    ~CircularQueue() {
        delete[] queue;
    }
};

int main() {
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;

    CircularQueue queue(size); // Create a CircularQueue of the given size

    int choice;
    do {
        // Display menu options
        cout << "\n1. Add Customer\n2. Checkout Customer\n3. View Queue\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            // Option to add a customer to the queue
            Customer customer;
            customer.read(); // Read customer details
            queue.add(customer); // Add customer to the queue
            break;
        }
        case 2:
            // Option to remove a customer from the queue
            queue.remove();
            break;
        case 3:
            // Option to display all customers in the queue
            queue.displayQueue();
            break;
        case 4:
            // Option to exit the program
            cout << "Exiting..." << endl;
            break;
        default:
            // Handle invalid choices
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 4); // Loop until the user chooses to exit

    return 0;
}
