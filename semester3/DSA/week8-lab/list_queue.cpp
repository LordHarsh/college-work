// list iplementation of queue

#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node(int d){
        data = d;
        next = NULL;
    }
};

class Queue {
    public:
    Node *front;
    Node *rear;
    Queue (){
        front = NULL;
        rear = NULL;
    }
    void enqueue (){
        int data;
        cout << "Enter element: ";
        cin >> data;
        Node *newNode = new Node(data);
        newNode->next == NULL;
        if (front == NULL){
            front = newNode;
            rear = newNode;
        }
        rear->next = newNode;
        rear = newNode;
    }
    void dequeue () {
        if (front == NULL) {
            cout << "Underflow\n";
        }
        Node *temp = front;
        front = front -> next;
        cout << "Element is " << temp->data << endl;
        delete temp;
    }
    void peek () {
        if (front == NULL) {
            cout << "Underflow\n";
        }
        Node *temp = front;
        while(temp!=NULL) {
            cout << temp->data << " ";
            temp = temp->next;
    }
        cout << endl;
    }
};

int main() {
    Queue queue;
    int choice;
    while (true){
    cout << "Enter Choice\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Peek\n";
    cout << "4. Exit\n";
    cin >> choice;
    switch (choice){
        case 1:
            queue.enqueue();
            break;
        case 2:
            queue.dequeue();
            break;
        case 3:
            queue.peek();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Invalid Choice";
            break;
    }
    }
    return 0;
}