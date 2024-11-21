#include <iostream>
#include <string>

using namespace std;

class BrowserHistory {
private:
    string* history; // Pointer to dynamically allocated array
    int capacity;    // Current capacity of the array
    int top;         // Index of the current page (-1 indicates no pages visited)

public:
    // Constructor to initialize the browser history
    BrowserHistory() {
        history = nullptr; // Initialize history pointer to nullptr
        capacity = 0;      // No initial capacity
        top = -1;          // No pages visited initially
    }

    // Destructor to free allocated memory
    ~BrowserHistory() {
        delete[] history; // Free the dynamic array
    }

    // Function to add a visited page
    void addVisitedPage(const string& page) {
    string* newHistory = new string[++capacity]; // Create a new array with increased capacity
    for (int i = 0; i <= top; ++i) {             // Copy old history
        newHistory[i] = history[i];
    }
    delete[] history;       // Free the old memory
    history = newHistory;   // Update history pointer
    history[++top] = page;  // Add the new page
    cout << "Visited: " << page << endl;
}


    // Function to navigate back to the previous page
    void navigateBack() {
        if (top > 0) {
            cout << "Navigating back from: " << history[top] << endl;
            --top; // Go back to the previous page
            cout << "Current page is now: " << history[top] << endl;
        } else if (top == 0) {
            cout << "Navigating back from: " << history[top] << endl;
            cout << "No previous page to go back to." << endl;
        } else {
            cout << "No history to go back to." << endl;
        }
    }

    // Function to view the current page
    void viewCurrentPage() {
        if (top >= 0) {
            cout << "Current page: " << history[top] << endl;
        } else {
            cout << "No pages visited yet." << endl;
        }
    }

    // Function to check if the history is empty
    bool isHistoryEmpty() {
        return top == -1; // Returns true if no pages have been visited
    }
};

int main() {
    BrowserHistory browserHistory;
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
