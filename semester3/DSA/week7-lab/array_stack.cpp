#include <iostream>
using namespace std;
// Online C compiler to run C program online
class Stack {
    public:
    int top;
    int capacity;
    int *arr;
    Stack (int size){
        top = -1;
        capacity = size;
        arr = new int[size];
    }
    void push (){
        int data;
        cout << "Enter element: ";
        cin >> data;
        if (top == capacity -1){
            cout << "Overflow";
        }
        top++;
        arr[top] = data;
    }
    void pop () {
        if (top == -1) {
            cout << "Underflow";
        }
        cout << "Element is " << arr[top];
        top--;
    }
    void peek () {
        if (top == -1) {
            cout << "Underflow";
        }
        for (int i = top; i >= 0; i--){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    // Write C code here
    int size;
    cout << "Enter size of stack: ";
    cin >> size;
    Stack stack(size);
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