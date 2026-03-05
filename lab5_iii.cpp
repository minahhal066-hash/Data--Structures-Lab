#include <iostream>
#include <string>
using namespace std;

struct Node{
    string name;
    int score;
    Node* next;
    Node* prev;
};

Node* head=NULL;

void addPlayer(string name,int score){
    Node* newNode=new Node();
    newNode->name=name;
    newNode->score=score;

    if(head==NULL || score<head->score){
        newNode->next=head;
        newNode->prev=NULL;

        if(head!=NULL)
            head->prev=newNode;

        head=newNode;
        return;
    }

    Node* temp=head;

    while(temp->next!=NULL && temp->next->score<score)
        temp=temp->next;

    newNode->next=temp->next;

    if(temp->next!=NULL)
        temp->next->prev=newNode;

    temp->next=newNode;
    newNode->prev=temp;
}

void deletePlayer(string name){
    Node* temp=head;

    while(temp!=NULL && temp->name!=name)
        temp=temp->next;

    if(temp==NULL){
        cout<<"Player not found\n";
        return;
    }

    if(temp->prev!=NULL)
        temp->prev->next=temp->next;
    else
        head=temp->next;

    if(temp->next!=NULL)
        temp->next->prev=temp->prev;

    delete temp;
}

void display(){
    Node* temp=head;

    while(temp!=NULL){
        cout<<temp->name<<" - "<<temp->score<<endl;
        temp=temp->next;
    }
}

void lowestScore(){
    if(head!=NULL)
        cout<<"Lowest Score Player: "<<head->name<<endl;
}

void sameScore(int score){
    Node* temp=head;

    while(temp!=NULL){
        if(temp->score==score)
            cout<<temp->name<<endl;

        temp=temp->next;
    }
}

void backwardFromPlayer(string name){
    Node* temp=head;

    while(temp!=NULL && temp->name!=name)
        temp=temp->next;

    if(temp==NULL) return;

    temp=temp->prev;

    while(temp!=NULL){
        cout<<temp->name<<" ";
        temp=temp->prev;
    }
}

int main(){
    addPlayer("Ali",72);
    addPlayer("Ahmed",65);
    addPlayer("Usman",72);
    addPlayer("Zain",60);

    display();

    cout<<"\nLowest Score:\n";
    lowestScore();

    cout<<"\nPlayers with score 72:\n";
    sameScore(72);

    cout<<"\nBackward from Usman:\n";
    backwardFromPlayer("Usman");

    deletePlayer("Ali");

    cout<<"\nAfter Deletion:\n";
    display();

    return 0;
}
