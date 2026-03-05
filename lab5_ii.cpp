#include <iostream>
using namespace std;

struct Node{
    float rain;
    Node* next;
    Node* prev;
};

Node* head=NULL;

void insertRain(float val){
    Node* newNode=new Node();
    newNode->rain=val;
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

void rainfallStats(){
    Node* temp=head;

    float total=0;
    float max=head->rain;
    float min=head->rain;

    int day=1,maxDay=1,minDay=1;

    while(temp!=NULL){
        total+=temp->rain;

        if(temp->rain>max){
            max=temp->rain;
            maxDay=day;
        }

        if(temp->rain<min){
            min=temp->rain;
            minDay=day;
        }

        temp=temp->next;
        day++;
    }

    cout<<"Total Rainfall: "<<total<<endl;
    cout<<"Average Rainfall: "<<total/7<<endl;
    cout<<"Highest Rainfall Day: "<<maxDay<<endl;
    cout<<"Lowest Rainfall Day: "<<minDay<<endl;
}

void rainfallAfter5(){
    Node* temp=head;

    for(int i=1;i<6;i++)
        temp=temp->next;

    if(temp!=NULL)
        cout<<"Rainfall after 5th node: "<<temp->rain<<endl;
}

int main(){
    float val;

    for(int i=1;i<=7;i++){
        do{
            cout<<"Enter rainfall for day "<<i<<": ";
            cin>>val;

            if(val<0)
                cout<<"Negative value not allowed\n";

        }while(val<0);

        insertRain(val);
    }

    rainfallStats();
    rainfallAfter5();

    return 0;
}
