#include <iostream>
using namespace std;

#define SIZE 5
int cq[SIZE];
int front = -1, rear = -1;

bool isEmpty() {
    return (front == -1);
}

bool isFull() {
    return ((rear + 1) % SIZE == front);
}

void enqueue(int x) {
    if (isFull()) {
        cout << "Circular Queue is Full!\n";
        return;
    }
    if (front == -1) front = 0; 
    rear = (rear + 1) % SIZE;
    cq[rear] = x;
    cout << x << " inserted\n";
}

void dequeue() {
    if (isEmpty()) {
        cout << "Circular Queue is Empty!\n";
        return;
    }
    cout << cq[front] << " removed\n";
    if (front == rear) {
        front = rear = -1; 
    } else {
        front = (front + 1) % SIZE;
    }
}

void peek() {
    if (isEmpty()) {
        cout << "Circular Queue is Empty!\n";
    } else {
        cout << "Front element: " << cq[front] << endl;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Circular Queue is Empty!\n";
        return;
    }
    cout << "Circular Queue elements: ";
    int i = front;
    while (true) {
        cout << cq[i] << " ";
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    cout << endl;
}

int main() {
    int choice, val;
    do {
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);
    return 0;
}
