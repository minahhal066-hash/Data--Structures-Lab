#include <iostream>
using namespace std;

#define SIZE 5

int queueArr[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) {
        cout << "Queue Overflow\n";
    } else {
        if (front == -1) front = 0;
        queueArr[++rear] = value;
    }
}

int countElements() {
    if (front == -1 || front > rear)
        return 0;
    return (rear - front + 1);
}

void display() {
    if (front == -1 || front > rear) {
        cout << "Queue is Empty\n";
    } else {
        cout << "Queue Elements: ";
        for (int i = front; i <= rear; i++) {
            cout << queueArr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    cout << "Number of elements in queue: " << countElements() << endl;

    return 0;
}