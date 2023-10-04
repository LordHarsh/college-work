// iplementing queue using array

#include <iostream>
using namespace std;

class Queue {
    public:
    int front;
    int rear;
    int size;
    int *arr;
    Queue (int s){
        front = -1;
        rear = -1;
        size = s;
        arr = new int[size];
    }
    void enqueue (){
        int data;
        cout << "Enter element: ";
        cin >> data;
        if (rear == size-1){
            cout << "Overflow\n";
        }
        else if (front == -1 && rear == -1){
            front = 0;
            rear = 0;
            arr[rear] = data;
        }
        else {
            rear++;
            arr[rear] = data;
        }
    }
    void dequeue () {
        if (front == -1 || front > rear) {
            cout << "Underflow\n";
        }
        else {
            cout << "Element is " << arr[front] << endl;
            front++;
        }
    }
    void peek () {
        if (front == -1 || front > rear) {
            cout << "Underflow\n";
        }
        else {
            for (int i = front; i <= rear; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue queue(5);
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
        default:
            cout << "Invalid Choice";
    }
    }
    return 0;
}