#include <iostream>
#include <string>

using namespace std;

// Class for a node in the circular linked list
class Route {
private:
    string route; // Route information (private member)
public:
    Route* next;  // Pointer to the next node

    // Constructor that initializes only the next pointer
    Route() { next = nullptr; }

    // Function to get input from the user
    void inputRoute() {
        cout << "Enter route name: ";
        getline(cin, route); // Get the route name from the user (allows spaces)
    }

    // Function to display the route
    void displayRoute() {
        cout << route; // Display the route
    }

    // Function to get the route name (getter)
    string getRoute() { // Removed const
        return route; // Return the route
    }
};

// Class for the circular linked list to manage routes
class NavigationSystem {
private:
    Route* head; // Pointer to the head of the list

public:
    // Constructor
    NavigationSystem() { head = nullptr; }

    // Destructor to free memory
    ~NavigationSystem() {
        if (head == nullptr) return; // If the list is empty

        Route* current = head;
        Route* nextNode;

        do {
            nextNode = current->next; // Store next node
            delete current; // Delete current node
            current = nextNode; // Move to the next node
        } while (current != head);
    }

    // Function to add a route to the circular linked list
    void addRoute() {
        Route* newRoute = new Route; // Create a new route
        newRoute->inputRoute(); // Get route name from user

        if (head == nullptr) { // If the list is empty
            head = newRoute;
            newRoute->next = head; // Point the new route to itself to form a circular list
        } else {
            Route* temp = head;
            while (temp->next != head) { // Traverse to the last node
                temp = temp->next;
            }
            temp->next = newRoute; // Link the last node to the new node
            newRoute->next = head; // Point the new node to the head
        }
        cout << "Route added: " << newRoute->getRoute() << endl; // Display the added route
    }

    // Function to remove a route from the circular linked list
    void removeRoute(string route) {
        if (head == nullptr) {
            cout << "No routes to remove." << endl;
            return;
        }

        // If the route to remove is the head
        if (head->getRoute() == route) {
            if (head->next == head) { // If there's only one node in the list
                delete head;
                head = nullptr;
            } else {
                Route* temp = head;
                // Traverse to the last node to update its next pointer
                while (temp->next != head) {
                    temp = temp->next;
                }
                temp->next = head->next;
                Route* toDelete = head;
                head = head->next; // Move head to the next node
                delete toDelete;
            }
            cout << "Route removed." << endl;
            return;
        }

        // General case for removing other nodes
        Route* current = head->next;
        Route* prev = head;

        while (current != head) {
            if (current->getRoute() == route) {
                prev->next = current->next;
                delete current;
                cout << "Route removed." << endl;
                return;
            }
            prev = current;
            current = current->next;
        }

        cout << "Route not found." << endl;
    }

    // Function to display all routes in the circular linked list
    void displayRoutes() {
        if (head == nullptr) {
            cout << "No routes available." << endl;
            return;
        }

        Route* temp = head;
        int index = 1; // Initialize index for display

        // Use a do-while loop to ensure the first node is displayed
        do {
            cout << "Route " << index << ": "; // Display format with index
            temp->displayRoute(); // Call displayRoute of Route class
            cout << endl; // New line after displaying route
            temp = temp->next; // Move to the next node
            index++; // Increment index
        } while (temp != head); // Stop when you circle back to the head
    }
};

int main() {
    NavigationSystem navigation;
    int choice;
    string route;

    while (true) {
        cout << "\nNavigation System" << endl;
        cout << "1. Add Route" << endl;
        cout << "2. Remove Route" << endl;
        cout << "3. Display Routes" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore leftover newline character after entering choice

        switch (choice) {
            case 1:
                navigation.addRoute(); // Call method to add route
                break;
            case 2:
                cout << "Enter route name to remove: ";
                getline(cin, route); // Get the route name to remove
                navigation.removeRoute(route);
                break;
            case 3:
                navigation.displayRoutes(); // Display all routes
                break;
            case 4:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
