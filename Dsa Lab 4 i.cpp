#include <iostream>
using namespace std;

struct Node
{
    string brand;
    int stock;
    float price;
    Node* next;
};

Node* head = NULL;

// Add Mobile at End
void addMobile()
{
    Node* newNode = new Node();

    cout << "\nEnter Brand Name: ";
    cin >> newNode->brand;

    cout << "Enter Units in Stock: ";
    cin >> newNode->stock;

    cout << "Enter Price: ";
    cin >> newNode->price;

    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    cout << "\nMobile Added Successfully!\n";
}

// Delete Mobile by Brand
void deleteMobile()
{
    if (head == NULL)
    {
        cout << "\nInventory is Empty!\n";
        return;
    }

    string b;
    cout << "\nEnter Brand Name to Delete: ";
    cin >> b;

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && temp->brand != b)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Mobile Not Found!\n";
        return;
    }

    if (prev == NULL)
    {
        head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    delete temp;
    cout << "Mobile Deleted Successfully!\n";
}

// Display All Mobiles
void displayMobiles()
{
    if (head == NULL)
    {
        cout << "\nNo Mobiles Available in Inventory!\n";
        return;
    }

    Node* temp = head;

    cout << "\n========== MOBILE INVENTORY ==========\n";

    while (temp != NULL)
    {
        cout << "Brand  : " << temp->brand << endl;
        cout << "Stock  : " << temp->stock << endl;
        cout << "Price  : " << temp->price << endl;
        cout << "--------------------------------------\n";
        temp = temp->next;
    }
}

int main()
{
    int choice;

    cout << "=====================================\n";
    cout << "     MOBILE STORE INVENTORY SYSTEM   \n";
    cout << "=====================================\n";

    do
    {
        cout << "\n1. Display All Mobiles";
        cout << "\n2. Add New Mobile";
        cout << "\n3. Delete Mobile";
        cout << "\n4. Exit";
        cout << "\n\nEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                displayMobiles();
                break;

            case 2:
                addMobile();
                break;

            case 3:
                deleteMobile();
                break;

            case 4:
                cout << "\nExiting Program... Thank You!\n";
                break;

            default:
                cout << "\nInvalid Choice! Try Again.\n";
        }

    } while (choice != 4);

    return 0;
}
 