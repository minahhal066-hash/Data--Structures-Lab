#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string bookId;
    string bookName;
    double bookPrice;
    string bookAuthor;
    string bookISBN;

public:
    Book() {}
    Book(string id, string name, double price, string author, string isbn) {
        bookId = id; bookName = name; bookPrice = price; bookAuthor = author; bookISBN = isbn;
    }

    string getId() { return bookId; }

    void setBook(string id, string name, double price, string author, string isbn) {
        bookId = id; bookName = name; bookPrice = price; bookAuthor = author; bookISBN = isbn;
    }

    void print() {
        cout << "ID: " << bookId 
             << ", Name: " << bookName 
             << ", Price: " << bookPrice 
             << ", Author: " << bookAuthor 
             << ", ISBN: " << bookISBN << endl;
    }
};

class Node {
public:
    Book book;
    Node* next;

    Node(Book b) { book = b; next = NULL; }
};

class BookList {
private:
    Node* head = NULL;

public:
    void addBook(Book b) {
        Node* newNode = new Node(b);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    void removeBook(string id) {
        if (head == NULL) { cout << "List empty\n"; return; }
        Node *curr = head, *prev = NULL;
        do {
            if (curr->book.getId() == id) {
                if (prev != NULL) prev->next = curr->next;
                else {
                    Node* temp = head;
                    while (temp->next != head) temp = temp->next;
                    head = head->next;
                    temp->next = head;
                }
                delete curr;
                cout << "Book deleted successfully\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);
        cout << "Book ID not found\n";
    }

    void updateBook(string id, Book b) {
        if (head == NULL) { cout << "List empty\n"; return; }
        Node* temp = head;
        do {
            if (temp->book.getId() == id) {
                temp->book = b;
                cout << "Book updated successfully\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Book ID not found\n";
    }

    void printBooks() {
        if (head == NULL) { cout << "List empty\n"; return; }
        Node* temp = head;
        cout << "\nAll Books:\n";
        do { temp->book.print(); temp = temp->next; } while (temp != head);
    }

    void printBook(string id) {
        if (head == NULL) { cout << "List empty\n"; return; }
        Node* temp = head;
        do {
            if (temp->book.getId() == id) { temp->book.print(); return; }
            temp = temp->next;
        } while (temp != head);
        cout << "Book ID not found\n";
    }
};

int main() {
    BookList list;
    int choice;
    string id, name, author, isbn;
    double price;

    do {
        cout << "\n--- Book Management Menu ---\n";
        cout << "1. Add Book\n";
        cout << "2. Delete Book\n";
        cout << "3. Update Book\n";
        cout << "4. Display All Books\n";
        cout << "5. Display Single Book\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Book ID: "; cin >> id;
                cout << "Enter Book Name: "; cin >> name;
                cout << "Enter Book Price: "; cin >> price;
                cout << "Enter Author Name: "; cin >> author;
                cout << "Enter ISBN: "; cin >> isbn;
                list.addBook(Book(id, name, price, author, isbn));
                break;

            case 2:
                cout << "Enter Book ID to delete: "; cin >> id;
                list.removeBook(id);
                break;

            case 3:
                cout << "Enter Book ID to update: "; cin >> id;
                cout << "Enter New Book Name: "; cin >> name;
                cout << "Enter New Book Price: "; cin >> price;
                cout << "Enter New Author Name: "; cin >> author;
                cout << "Enter New ISBN: "; cin >> isbn;
                list.updateBook(id, Book(id, name, price, author, isbn));
                break;

            case 4:
                list.printBooks();
                break;

            case 5:
                cout << "Enter Book ID to display: "; cin >> id;
                list.printBook(id);
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}