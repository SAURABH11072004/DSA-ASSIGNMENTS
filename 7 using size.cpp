#include <iostream>
#include <string>

using namespace std;

class BrowserHistory {
private:
    string* history; // Pointer to the array
    int capacity;    // Total capacity of the array
    int top;         // Index of the current page

public:
    // Constructor to initialize with a fixed capacity
    BrowserHistory(int initialCapacity = 10) { // Default capacity of 10
        capacity = initialCapacity;
        history = new string[capacity]; // Allocate array with predefined size
        top = -1; // No pages visited initially
    }

    // Destructor to free allocated memory
    ~BrowserHistory() {
        delete[] history;
    }

    // Function to add a visited page
    void addVisitedPage(const string& page) {
        if (top == capacity - 1) { // Check if array is full
            cout << "History is full. Cannot add more pages." << endl;
            return;
        }
        history[++top] = page; // Add the new page and increment the top
        cout << "Visited: " << page << endl;
    }

    // Function to view the current page
    void viewCurrentPage() {
        if (top >= 0) {
            cout << "Current page: " << history[top] << endl;
        } else {
            cout << "No pages visited yet." << endl;
        }
    }

    // Function to navigate back
    void navigateBack() {
        if (top > 0) {
            cout << "Navigating back from: " << history[top--] << endl;
            cout << "Current page is now: " << history[top] << endl;
        } else if (top == 0) {
            cout << "Navigating back from: " << history[top--] << endl;
            cout << "No previous page to go back to." << endl;
        } else {
            cout << "No history to go back to." << endl;
        }
    }

    // Function to check if the history is empty
    bool isHistoryEmpty() {
        return top == -1;
    }
};

int main() {
    BrowserHistory browserHistory(5); // Browser history with a capacity of 5
    int choice;
    string page;

    do {
        cout << "\nBrowser History Management System" << endl;
        cout << "1. Add Visited Page" << endl;
        cout << "2. Navigate Back" << endl;
        cout << "3. View Current Page" << endl;
        cout << "4. Check if History is Empty" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter page URL: ";
                cin >> page;
                browserHistory.addVisitedPage(page);
                break;
            case 2:
                browserHistory.navigateBack();
                break;
            case 3:
                browserHistory.viewCurrentPage();
                break;
            case 4:
                if (browserHistory.isHistoryEmpty()) {
                    cout << "History is empty." << endl;
                } else {
                    cout << "History is not empty." << endl;
                }
                break;
            case 5:
                cout << "Exiting the program" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
