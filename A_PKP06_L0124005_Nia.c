#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

// Define struct Book to store book information
struct Book {
    string title;
    string author;
    int year;
    string publisher;
};

// Function to input book data
void inputBookData(Book& book) {
    cout << "Enter book details:\n";
    
    cout << "Title: ";
    getline(cin, book.title);
    
    cout << "Author: ";
    getline(cin, book.author);
    
    // Input validation for year of publication
    while (true) {
        cout << "Year of Publication: ";
        cin >> book.year;

        if(cin.fail()) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a valid year.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            break;
        }
    }
    
    cout << "Publisher: ";
    getline(cin, book.publisher);
}

// Function to display book data
void displayBookData(const Book& book) {
    cout << "\nBook Details:\n";
    cout << left << setw(15) << "Title: " << book.title << endl;
    cout << left << setw(15) << "Author: " << book.author << endl;
    cout << left << setw(15) << "Year: " << book.year << endl;
    cout << left << setw(15) << "Publisher: " << book.publisher << endl;
}

int main() {
    Book myBook;

    inputBookData(myBook);
    displayBookData(myBook);

    return 0;
}
