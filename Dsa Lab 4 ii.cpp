#include <iostream>
using namespace std;

struct Profile
{
    string name;
    int age;
    string city;
    Profile* next;
};

Profile* head = NULL;

// Create Profile (Add at End)
void createProfile()
{
    Profile* newNode = new Profile();

    cout << "\nEnter Name: ";
    cin >> newNode->name;

    cout << "Enter Age: ";
    cin >> newNode->age;

    cout << "Enter City: ";
    cin >> newNode->city;

    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Profile* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    cout << "\nProfile Created Successfully!\n";
}

// View All Profiles
void viewProfiles()
{
    if (head == NULL)
    {
        cout << "\nNo Profiles Available!\n";
        return;
    }

    Profile* temp = head;

    cout << "\n========== ALL USER PROFILES ==========\n";

    while (temp != NULL)
    {
        cout << "Name : " << temp->name << endl;
        cout << "Age  : " << temp->age << endl;
        cout << "City : " << temp->city << endl;
        cout << "---------------------------------------\n";
        temp = temp->next;
    }
}

// Search Profile
void searchProfile()
{
    if (head == NULL)
    {
        cout << "\nNo Profiles Available!\n";
        return;
    }

    string n;
    cout << "\nEnter Name to Search: ";
    cin >> n;

    Profile* temp = head;

    while (temp != NULL && temp->name != n)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Profile Not Found!\n";
    }
    else
    {
        cout << "\nProfile Found!\n";
        cout << "Name : " << temp->name << endl;
        cout << "Age  : " << temp->age << endl;
        cout << "City : " << temp->city << endl;
    }
}

// Update Profile
void updateProfile()
{
    if (head == NULL)
    {
        cout << "\nNo Profiles Available!\n";
        return;
    }

    string n;
    cout << "\nEnter Name to Update: ";
    cin >> n;

    Profile* temp = head;

    while (temp != NULL && temp->name != n)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Profile Not Found!\n";
    }
    else
    {
        cout << "Enter New Age: ";
        cin >> temp->age;

        cout << "Enter New City: ";
        cin >> temp->city;

        cout << "Profile Updated Successfully!\n";
    }
}

// Delete Profile
void deleteProfile()
{
    if (head == NULL)
    {
        cout << "\nNo Profiles Available!\n";
        return;
    }

    string n;
    cout << "\nEnter Name to Delete: ";
    cin >> n;

    Profile* temp = head;
    Profile* prev = NULL;

    while (temp != NULL && temp->name != n)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Profile Not Found!\n";
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

    cout << "Profile Deleted Successfully!\n";
}

int main()
{
    int choice;

    cout << "======================================\n";
    cout << "      SOCIAL MEDIA PROFILE SYSTEM     \n";
    cout << "======================================\n";

    do
    {
        cout << "\n1. View All Profiles";
        cout << "\n2. Create New Profile";
        cout << "\n3. Search Profile";
        cout << "\n4. Update Profile";
        cout << "\n5. Delete Profile";
        cout << "\n6. Exit";
        cout << "\n\nEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                viewProfiles();
                break;

            case 2:
                createProfile();
                break;

            case 3:
                searchProfile();
                break;

            case 4:
                updateProfile();
                break;

            case 5:
                deleteProfile();
                break;

            case 6:
                cout << "\nExiting Program... Thank You!\n";
                break;

            default:
                cout << "\nInvalid Choice! Try Again.\n";
        }

    } while (choice != 6);

    return 0;
}