#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string name;
    Node* next;
};

Node* head = NULL;

// Add Employee
void addEmployee(string name)
{
    Node* newNode = new Node();
    newNode->name = name;

    if(head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        Node* temp = head;
        while(temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    cout << "Added successfully\n";
}

// Delete Employee
void deleteEmployee(string name)
{
    if(head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node *curr = head, *prev = NULL;

    do
    {
        if(curr->name == name)
        {
            if(prev != NULL)
                prev->next = curr->next;

            else
            {
                Node* temp = head;
                while(temp->next != head)
                    temp = temp->next;

                head = head->next;
                temp->next = head;
            }

            delete curr;
            cout << "Deleted successfully\n";
            return;
        }

        prev = curr;
        curr = curr->next;

    } while(curr != head);

    cout << "Employee not found\n";
}

// Search Employee
void searchEmployee(string name)
{
    if(head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;

    do
    {
        if(temp->name == name)
        {
            cout << "Found successfully\n";
            return;
        }

        temp = temp->next;

    } while(temp != head);

    cout << "Employee not found\n";
}

// Update Employee
void updateEmployee(string oldName, string newName)
{
    Node* temp = head;

    if(head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    do
    {
        if(temp->name == oldName)
        {
            temp->name = newName;
            cout << "Updated successfully\n";
            return;
        }

        temp = temp->next;

    } while(temp != head);

    cout << "Employee not found\n";
}

// Display Employees
void display()
{
    if(head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;

    cout << "\nEmployee List:\n";

    do
    {
        cout << temp->name << endl;
        temp = temp->next;

    } while(temp != head);
}

int main()
{
    int choice;
    string name, newName;

    do
    {
        cout << "\n1. Add Employee";
        cout << "\n2. Delete Employee";
        cout << "\n3. Search Employee";
        cout << "\n4. Update Employee";
        cout << "\n5. Display Employees";
        cout << "\n6. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter employee name: ";
                cin >> name;
                addEmployee(name);
                break;

            case 2:
                cout << "Enter employee name to delete: ";
                cin >> name;
                deleteEmployee(name);
                break;

            case 3:
                cout << "Enter employee name to search: ";
                cin >> name;
                searchEmployee(name);
                break;

            case 4:
                cout << "Enter employee name to update: ";
                cin >> name;
                cout << "Enter new name: ";
                cin >> newName;
                updateEmployee(name,newName);
                break;

            case 5:
                display();
                break;

        }

    } while(choice != 6);

    return 0;
}