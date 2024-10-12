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
        cin.ignore(); // Ignore leftover newline character from previous input
        getline(cin, route); // Get the route name from the user (allows spaces)
    }

    // Function to display the route
    void displayRoute() {
        cout << route; // Display the route
    }

    // Function to get the route name (getter)
    string& getRoute() { // Removed const
        return route; // Return the route
    }
};

// Class for the circular linked list to manage routes
class NavigationSystem {
private:
    Route* head; // Pointer to the head of the list

public:
    // Constructor
    NavigationSystem() : head(nullptr) {}

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
            head->next = head; // Point to itself
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
    void removeRoute(const string& route) {
        if (head == nullptr) {
            cout << "No routes to remove." << endl;
            return;
        }

        Route* current = head;
        Route* previous = nullptr;

        // Search for the route
        do {
            if (current->getRoute() == route) { // Use the getter method
                // If the node to remove is the head
                if (current == head) {
                    if (head->next == head) { // Only one node
                        delete head;
                        head = nullptr;
                    } else {
                        // Find the last node
                        Route* temp = head;
                        while (temp->next != head) {
                            temp = temp->next;
                        }
                        temp->next = head->next; // Bypass the head
                        Route* oldHead = head;
                        head = head->next; // Move head to the next node
                        delete oldHead; // Delete old head
                    }
                } else {
                    previous->next = current->next; // Bypass the current node
                    delete current; // Delete the current node
                }
                cout << "Route removed: " << route << endl;
                return;
            }
            previous = current;
            current = current->next;
        } while (current != head);

        cout << "Route not found: " << route << endl;
    }

    // Function to display all routes in the circular linked list
    void displayRoutes() {
        if (!head) {
            cout << "No routes available." << endl;
            return;
        }

        Route* temp = head;
        int index = 1; // Initialize index for display
        cout << "Routes: " << endl;
        do {
            cout << "Route " << index << ": "; // Display format with index
            temp->displayRoute(); // Call displayRoute of Route class
            cout << endl; // New line after displaying route
            temp = temp->next;
            index++; // Increment index
        } while (temp != head);
    }
};

int main() {
    NavigationSystem navigation;
    int choice;
    string route;

    do {
        cout << "\nDelivery Service Navigation System" << endl;
        cout << "1. Add Route" << endl;
        cout << "2. Remove Route" << endl;
        cout << "3. Display Routes" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                navigation.addRoute(); // Call method to add route
                break;
            case 2:
                cout << "Enter route name to remove: ";
                cin.ignore(); // Ignore leftover newline character
                getline(cin, route); // Get the route name to remove
                navigation.removeRoute(route);
                break;
            case 3:
                navigation.displayRoutes();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
