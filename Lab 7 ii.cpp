#include <iostream>
using namespace std;

// Inventory class
class Inventory {
private:
    int serialNum;
    int manufactYear;
    int lotNum;

public:
    Inventory() {}

    void setData(int s, int y, int l) {
        serialNum = s;
        manufactYear = y;
        lotNum = l;
    }

    void display() {
        cout << "Serial#: " << serialNum
             << ", Manufacture Year: " << manufactYear
             << ", Lot#: " << lotNum << endl;
    }
};

// Node for stack
class Node {
public:
    Inventory data;
    Node* next;

    Node(Inventory i) {
        data = i;
        next = nullptr;
    }
};

// Stack class using linked list
class InventoryStack {
private:
    Node* top;

public:
    InventoryStack() { top = nullptr; }

    void push(Inventory i) {
        Node* newNode = new Node(i);
        newNode->next = top;
        top = newNode;
        cout << "Part added to inventory.\n";
    }

    void pop() {
        if (top == nullptr) {
            cout << "Inventory is empty.\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << "Removed part from inventory: "; temp->data.display();
        delete temp;
    }

    void display() {
        if (top == nullptr) {
            cout << "Inventory is empty.\n";
            return;
        }
        Node* temp = top;
        cout << "\nRemaining parts in inventory:\n";
        while (temp != nullptr) {
            temp->data.display();
            temp = temp->next;
        }
    }
};

int main() {
    InventoryStack stack;
    int choice;

    do {
        cout << "\n1. Add Part to Inventory\n2. Take Part from Inventory\n3. Display Remaining Inventory\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int s, y, l;
            cout << "Enter Serial Number: "; cin >> s;
            cout << "Enter Manufacture Year: "; cin >> y;
            cout << "Enter Lot Number: "; cin >> l;
            Inventory i; i.setData(s, y, l);
            stack.push(i);
        }
        else if (choice == 2) {
            stack.pop();
        }
        else if (choice == 3) {
            stack.display();
        }
        else if (choice == 4) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}