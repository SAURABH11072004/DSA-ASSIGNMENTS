#include<iostream> 
#define SIZE 5 
using namespace std; 
 
class Customer{ 
    string customerName; 
    int contact; 
public: 
    void read(){ 
        cout << "Enter the name of the customer: "; 
        cin >> customerName; 
        cout << "Enter the contact number: "; 
        cin >> contact; 
    } 
    void display(){ 
        cout << "Name of the customer is: " << customerName << endl; 
        cout << "Contact Number: " << contact << endl; 
    } 
}; 
 
class CircularQueue{ 
    Customer q[SIZE]; 
    int front, rear; 
public: 
    CircularQueue(){ 
        front = rear = -1; 
    } 
     
    bool isFull(){ 
        if ((front == 0 && rear == SIZE - 1) || (front == (rear + 1) % SIZE)){ 
            return true; 
        } 
        return false; 
    } 
     
    bool isEmpty(){ 
        return (front == -1); 
    } 
     
    void CustomerArrival(Customer element){ 
        if (isFull()){ 
            cout << "Queue is Full. Cannot add more customers." << endl; 
        } 
        else { 
            if (front == -1) front = 0; 
            rear = (rear + 1) % SIZE; 
            q[rear] = element; 
            cout << "Customer added to the queue." << endl; 
        } 
    } 
     
    Customer CustomerCheckout(){ 
        Customer element; 
        if (isEmpty()){ 
            cout << "Queue is Empty. No customers to checkout." << endl; 
        } 
        else { 
            element = q[front]; 
            cout << "Customer checking out: "; 
            element.display(); 
            if (front == rear){ 
                front = rear = -1; 
            } 
            else { 
                front = (front + 1) % SIZE; 
            } 
        } 
        return element; 
    } 
     
    void closeCounter(){ 
        if (!isEmpty()){ 
            cout << "Counter closed. Remaining customers being checked out." << endl; 
            while (!isEmpty()){ 
                CustomerCheckout(); 
            } 
        } 
        else { 
            cout << "Counter already empty. No customers to check out." << endl; 
        } 
    } 
 
    void viewCustomer(){ 
        if (isEmpty()){ 
            cout << "Queue is Empty. No customers to view." << endl; 
        } 
        else { 
            cout << "Customers in the queue: " << endl; 
            int i = front; 
            while (true) { 
                q[i].display(); 
                if (i == rear) break; 
                i = (i + 1) % SIZE; 
            } 
        } 
    } 
}; 
 
int main(){ 
    int choice; 
    CircularQueue cq; 
    Customer c; 
     
    do { 
        cout << "\n1. Customer Arrival\n2. Customer Checkout\n3. View Customers\n4. Close Checkout Counter\n5. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        switch (choice) { 
            case 1: 
                c.read(); 
                cq.CustomerArrival(c); 
                break; 
            case 2: 
                cq.CustomerCheckout(); 
                break; 
            case 3: 
                cq.viewCustomer(); 
                break; 
            case 4: 
                cq.closeCounter(); 
                break; 
                case 5:
                cout<<"existing";
                break;
            default: 
                cout << "Invalid choice. Please try again." << endl;
                break;
        } 
    } while (choice != 5); 
 
    return 0; 
} 
 
 
