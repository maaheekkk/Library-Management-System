#include <iostream>
#include <string>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
    bool issued;
    Book* next;
};

Book* head = NULL;

// Add Book
void addBook() {
    Book* newBook = new Book;

    cout << "Enter Book ID: ";
    cin >> newBook->id;
    cin.ignore();

    cout << "Enter Book Title: ";
    getline(cin, newBook->title);

    cout << "Enter Author Name: ";
    getline(cin, newBook->author);

    newBook->issued = false;
    newBook->next = NULL;

    if (head == NULL) {
        head = newBook;
    } else {
        Book* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newBook;
    }

    cout << "\nBook Added Successfully!\n";
}

// Display Books
void displayBooks() {
    if (head == NULL) {
        cout << "\nNo Books Available!\n";
        return;
    }

    Book* temp = head;

    cout << "\n----- Library Books -----\n";

    while (temp != NULL) {
        cout << "ID: " << temp->id << endl;
        cout << "Title: " << temp->title << endl;
        cout << "Author: " << temp->author << endl;
        cout << "Status: " << (temp->issued ? "Issued" : "Available") << endl;
        cout << "--------------------------\n";

        temp = temp->next;
    }
}

// Search by ID
void searchByID() {
    int id;
    cout << "Enter Book ID: ";
    cin >> id;

    Book* temp = head;

    while (temp != NULL) {
        if (temp->id == id) {
            cout << "\nBook Found!\n";
            cout << "Title: " << temp->title << endl;
            cout << "Author: " << temp->author << endl;
            cout << "Status: " << (temp->issued ? "Issued" : "Available") << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Book Not Found!\n";
}

// Search by Title
void searchByTitle() {
    cin.ignore();

    string title;
    cout << "Enter Book Title: ";
    getline(cin, title);

    Book* temp = head;

    while (temp != NULL) {
        if (temp->title == title) {
            cout << "\nBook Found!\n";
            cout << "ID: " << temp->id << endl;
            cout << "Author: " << temp->author << endl;
            cout << "Status: " << (temp->issued ? "Issued" : "Available") << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Book Not Found!\n";
}

// Delete Book
void deleteBook() {
    int id;
    cout << "Enter Book ID to Delete: ";
    cin >> id;

    Book *temp = head, *prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Book Not Found!\n";
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    delete temp;

    cout << "Book Deleted Successfully!\n";
}

// Issue Book
void issueBook() {
    int id;
    cout << "Enter Book ID to Issue: ";
    cin >> id;

    Book* temp = head;

    while (temp != NULL) {
        if (temp->id == id) {
            if (temp->issued)
                cout << "Book is Already Issued!\n";
            else {
                temp->issued = true;
                cout << "Book Issued Successfully!\n";
            }
            return;
        }
        temp = temp->next;
    }

    cout << "Book Not Found!\n";
}

// Return Book
void returnBook() {
    int id;
    cout << "Enter Book ID to Return: ";
    cin >> id;

    Book* temp = head;

    while (temp != NULL) {
        if (temp->id == id) {
            if (!temp->issued)
                cout << "Book was not Issued!\n";
            else {
                temp->issued = false;
                cout << "Book Returned Successfully!\n";
            }
            return;
        }
        temp = temp->next;
    }

    cout << "Book Not Found!\n";
}

// Main Function
int main() {
    int choice;

    do {
        cout << "\n====== Library Management System ======\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book by ID\n";
        cout << "4. Search Book by Title\n";
        cout << "5. Delete Book\n";
        cout << "6. Issue Book\n";
        cout << "7. Return Book\n";
        cout << "8. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addBook();
            break;
        case 2:
            displayBooks();
            break;
        case 3:
            searchByID();
            break;
        case 4:
            searchByTitle();
            break;
        case 5:
            deleteBook();
            break;
        case 6:
            issueBook();
            break;
        case 7:
            returnBook();
            break;
        case 8:
            cout << "Thank You!\n";
            break;
        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 8);

    return 0;
}