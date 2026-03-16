#include <iostream>
#include <string>
using namespace std;

// Node class for book
class BookNode {
public:
    string title;
    double price;
    string edition;
    int pages;
    BookNode* next;

    BookNode(string t, double p, string e, int pg) {
        title = t; price = p; edition = e; pages = pg;
        next = nullptr;
    }
};

// Stack class using linked list
class BookStack {
private:
    BookNode* top;

public:
    BookStack() { top = nullptr; }

    void push(string title, double price, string edition, int pages) {
        BookNode* newNode = new BookNode(title, price, edition, pages);
        newNode->next = top;
        top = newNode;
        cout << "Book pushed onto stack.\n";
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty.\n";
            return;
        }
        BookNode* temp = top;
        top = top->next;
        cout << "Popped book: " << temp->title << endl;
        delete temp;
    }

    void peek() {
        if (top == nullptr) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Top book: " << top->title << ", Price: " << top->price
             << ", Edition: " << top->edition << ", Pages: " << top->pages << endl;
    }

    void display() {
        if (top == nullptr) {
            cout << "Stack is empty.\n";
            return;
        }
        BookNode* temp = top;
        cout << "\nBooks in stack:\n";
        while (temp != nullptr) {
            cout << "Title: " << temp->title
                 << ", Price: " << temp->price
                 << ", Edition: " << temp->edition
                 << ", Pages: " << temp->pages << endl;
            temp = temp->next;
        }
    }
};

int main() {
    BookStack stack;
    string title, edition;
    double price;
    int pages;

    cout << "Push 5 books onto stack:\n";
    for (int i = 0; i < 5; i++) {
        cout << "Enter title: "; cin >> ws; getline(cin, title);
        cout << "Enter price: "; cin >> price;
        cout << "Enter edition: "; cin >> edition;
        cout << "Enter pages: "; cin >> pages;
        stack.push(title, price, edition, pages);
        cout << endl;
    }

    cout << "\nPeek top book:\n";
    stack.peek();

    cout << "\nPop 2 books:\n";
    stack.pop();
    stack.pop();

    cout << "\nRemaining books in stack:\n";
    stack.display();

    return 0;
}