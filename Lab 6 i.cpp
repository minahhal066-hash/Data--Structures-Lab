#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head = NULL;

void insertBefore(int val){
    Node* newNode = new Node();
    newNode->data = val;

    if(head == NULL){
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while(temp->next != head)
        temp = temp->next;

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

// Insert at end
void insertAfter(int val){
    Node* newNode = new Node();
    newNode->data = val;

    if(head == NULL){
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while(temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

// Delete node
void deleteNode(int key){
    if(head == NULL) return;

    Node *curr = head, *prev = NULL;

    if(head->data == key && head->next == head){
        delete head;
        head = NULL;
        return;
    }

    if(head->data == key){
        Node* temp = head;
        while(temp->next != head)
            temp = temp->next;

        head = head->next;
        temp->next = head;
        delete curr;
        return;
    }

    do{
        prev = curr;
        curr = curr->next;
    }while(curr != head && curr->data != key);

    if(curr->data == key){
        prev->next = curr->next;
        delete curr;
    }
}

void display(){
    if(head == NULL) return;

    Node* temp = head;
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != head);

    cout << endl;
}

int main(){

    insertBefore(10);
    insertBefore(5);
    insertAfter(20);
    insertAfter(30);

    cout << "Circular List: ";
    display();

    deleteNode(20);

    cout << "After Deletion: ";
    display();

    return 0;
}