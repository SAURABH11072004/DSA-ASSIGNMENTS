#include <iostream>
#include <string>   // Include for std::string

using namespace std;

// Class representing a single song in the playlist
class Song {
    string title;      // Title of the song
    string artist;     // Artist of the song
    float duration;    // Duration of the song in minutes
    Song* next;        // Pointer to the next song in the linked list

public:
    // Constructor to initialize song attributes
    Song() { next=nullptr;}  // Initialize next pointer to nullptr

    // Method to get data for a song from the user
    void getdata() {
        cout << "Enter title name: ";
       // Clear input buffer before getline
        getline(cin, title); // Read title, allowing spaces in the title
        cout << "Enter artist name: ";
        getline(cin, artist); // Read artist name, allowing spaces
        cout << "Enter duration (in minutes): ";
        cin >> duration; // Read duration of the song
    }

    // Method to display the details of the song
    void display()  {
        cout << "Title: " << title << endl;     // Print title
        cout << "Artist: " << artist << endl;   // Print artist
        cout << "Duration: " << duration << " minutes" << endl; // Print duration
    }

    // Accessor methods to get private member values
    string getTitle()  { return title; }       // Get the title of the song
    string getArtist()  { return artist; }     // Get the artist of the song
    float getDuration() { return duration; }   // Get the duration of the song

    // Friend class declaration allows Playlist class to access private members
    friend class Playlist;
};

// Playlist class to manage the linked list of songs
class Playlist {
    Song* head; // Pointer to the head (first song) of the linked list

public:
    // Constructor to initialize an empty playlist
    Playlist() { head=nullptr; } // Inline constructor initializes head to nullptr

    // Method to add a song to the playlist
    void addSong() {
        Song* newSong = new Song; // Create a new song instance
        newSong->getdata();       // Get the song's details from the user
       

        if (head == nullptr) {
            head = newSong; // If the playlist is empty, the new song is the head
        } else {
            Song* temp = head; // Temporary pointer to traverse the list
            while (temp->next!=NULL) {
                temp = temp->next; // Traverse to the end of the list
            }
            temp->next = newSong; // Add the new song to the end of the list
        }
        cout << "Song added to playlist." << endl; // Confirmation message
    }

    // Method to remove a song by title
    void removeSong(string& title) {
        if (head == nullptr) { // Check if the playlist is empty
            cout << "Playlist is empty." << endl;
            return; // Exit if the playlist is empty
        }

        // Special case: Removing the head song
        if (head->getTitle() == title) {
            Song* temp = head; // Store the current head
            head = head->next; // Move head to the next song
            delete temp;       // Free the old head
            cout << "Song removed from playlist." << endl; // Confirmation message
            return; // Exit after removing the head
        }

        // General case: Find the song in the list
        Song* current = head; // Pointer to traverse the list
        Song* previous = nullptr; // Pointer to keep track of the previous song

        // Traverse the list to find the song to remove
        while (current!=nullptr && current->getTitle() != title) {
            previous = current;      // Move previous to current
            current = current->next; // Move to the next song
        }

        if (current!=nullptr) { // If the song was found
            previous->next = current->next;  // Remove the current song from the list
            delete current;                   // Free the removed song
            cout << "Song removed from playlist." << endl; // Confirmation message
        } else {
            cout << "Song not found in the playlist." << endl; // If the song was not found
        }
    }

    // Method to display all songs in the playlist
    void displayPlaylist()  {
        if (head == nullptr) { // Check if the playlist is empty
            cout << "Playlist is empty." << endl;
            return; // Exit if the playlist is empty
        }

        cout << "--- Playlist ---" << endl; // Header for the playlist
        Song* temp = head; // Temporary pointer to traverse the list
        while (temp!=NULL) { // Loop through all songs
            temp->display();  // Display each song's details
            cout << "----------------" << endl; // Separator for clarity
            temp = temp->next; // Move to the next song
        }
    }

    // Method to play a specific song by title
    void playSong(string& title)  {
        if (head == nullptr) { // Check if the playlist is empty
            cout << "Playlist is empty." << endl;
            return; // Exit if the playlist is empty
        }

        Song* temp = head; // Temporary pointer to traverse the list
        while (temp!=nullptr) { // Loop through all songs
            if (temp->getTitle() == title) { // Check if the song title matches
                cout << "Playing song: " << endl; // Indicate that the song is playing
                temp->display();  // Display the song details
                return; // Exit after playing the song
            }
            temp = temp->next; // Move to the next song
        }
        cout << "Song not found in the playlist." << endl; // If the song was not found
    }

    // Destructor to free allocated memory
    ~Playlist() {
        while (head!=nullptr) { // Loop until all songs are deleted
            Song* temp = head; // Store the current head
            head = head->next; // Move head to the next song
            delete temp;  // Delete the old head
        }
    }
};

// Main function to drive the program
int main() {
    Playlist playlist;  // Create a playlist object
    int choice; // Variable to hold user choice
    string title; // Variable to hold the song title

    do {
        // Display menu options to the user
        cout << "\n--- Music Player Playlist Menu ---\n";
        cout << "1. Add Song\n";
        cout << "2. Remove Song\n";
        cout << "3. Display Playlist\n";
        cout << "4. Play Specific Song\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice; // Read user choice
        cin.ignore(); // Clear input buffer before the next choice

        switch (choice) { // Handle user choice
            case 1:
                playlist.addSong();  // Add a song to the playlist
                break;
            case 2:
                cout << "Enter the title of the song to remove: ";
                getline(cin, title); // Read title of the song to remove
                playlist.removeSong(title);  // Remove a song by title
                break;
            case 3:
                playlist.displayPlaylist();  // Display all songs in the playlist
                break;
            case 4:
                cout << "Enter the title of the song to play: ";
                getline(cin, title); // Read title of the song to play
                playlist.playSong(title);  // Play a specific song by title
                break;
            case 5:
                cout << "Exiting the music player." << endl; // Exit message
                break;
            default:
                cout << "Invalid choice! Please try again." << endl; // Error message for invalid input
                break;
        }

    } while (choice != 5);  // Exit the loop when choice is 5

    return 0;  // Indicate successful termination of the program
}
