#include <iostream>
using namespace std;
// Online C compiler to run C program online
class Node {
    public:
    int data;
    Node *next;
    Node(int d){
        data = d;
        next = NULL;
    }
};
class Stack {
    public:
    Node *top;
    Stack (){
        top = NULL;
    }
    void push (){
        int data;
        cout << "Enter element: ";
        cin >> data;
        Node *newNode = new Node(data);
        newNode->next == NULL;
        if (top == NULL){
            top = newNode;
        }
        newNode->next = top;
        top = newNode;
    }
    void pop () {
        if (top == NULL) {
            cout << "Underflow";
        }
        Node *temp = top;
        top = top -> next;
        cout << "Element is " << temp->data;
        delete temp;
    }
    void peek () {
        if (top == NULL) {
            cout << "Underflow";
        }
        Node *temp = top;
        while(temp!=NULL) {
            cout << temp->data << " ";
            temp = temp->next;
    }
        cout << endl;
    }
};
int main() {
    // Write C code here
    Stack stack;
    int choice;
    while (true){
    cout << "Enter Choice\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Peek\n";
    cout << "0. EXIT\n";
    cin >> choice;
    switch (choice) {
        case 1:
        stack.push();
        break;
        case 2:
        stack.pop();
        break;
        case 3:
        stack.peek();
        break;
        case 0:
        exit(0);
        break;
        default:
        cout << "Invalid";
    }
    }
    return 0;
}