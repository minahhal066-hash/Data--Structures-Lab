#include <iostream>
using namespace std;

struct Node{
    int marks;
    Node* next;
    Node* prev;
};

Node* head=NULL;

void createList(){
    int n,val;
    cout<<"Enter number of nodes: ";
    cin>>n;

    for(int i=0;i<n;i++){
        cout<<"Enter marks: ";
        cin>>val;

        Node* newNode=new Node();
        newNode->marks=val;
        newNode->next=NULL;
        newNode->prev=NULL;

        if(head==NULL)
            head=newNode;
        else{
            Node* temp=head;
            while(temp->next!=NULL)
                temp=temp->next;

            temp->next=newNode;
            newNode->prev=temp;
        }
    }
}

void display(){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->marks<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void addBeginning(int val){
    Node* newNode=new Node();
    newNode->marks=val;
    newNode->next=head;
    newNode->prev=NULL;

    if(head!=NULL)
        head->prev=newNode;

    head=newNode;
}

void addAfter45(int val){
    Node* temp=head;

    while(temp!=NULL && temp->marks!=45)
        temp=temp->next;

    if(temp==NULL){
        cout<<"45 not found\n";
        return;
    }

    Node* newNode=new Node();
    newNode->marks=val;

    newNode->next=temp->next;
    newNode->prev=temp;

    if(temp->next!=NULL)
        temp->next->prev=newNode;

    temp->next=newNode;
}

void deleteBeginning(){
    if(head==NULL) return;

    Node* temp=head;
    head=head->next;

    if(head!=NULL)
        head->prev=NULL;

    delete temp;
}

void deleteAfter45(){
    Node* temp=head;

    while(temp!=NULL && temp->marks!=45)
        temp=temp->next;

    if(temp==NULL || temp->next==NULL){
        cout<<"Node after 45 not found\n";
        return;
    }

    Node* del=temp->next;
    temp->next=del->next;

    if(del->next!=NULL)
        del->next->prev=temp;

    delete del;
}

int main(){
    createList();
    display();

    addBeginning(90);
    display();

    addAfter45(88);
    display();

    deleteBeginning();
    display();

    deleteAfter45();
    display();

    return 0;
}
