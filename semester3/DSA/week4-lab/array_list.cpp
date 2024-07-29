// write a cpp program to implement list using array

#include <iostream>
using namespace std;
class ArrayList {
    private:
        int* arr;
        int capacity;
        int size;
    public:
        ArrayList (int initialCapacity = 10) {
            capacity = initialCapacity;
            arr = new int[capacity];
            size = 0;
        }
        void insert(int element, int position) {
            if (position < 0 || position > size) {
                cout << "Invalid position" << endl;
                return;
            }
            if (size==capacity) {
                capacity *= 2;
                int* temp = new int[capacity];
                for (int i=0; i<size; i++) {
                    temp[i] = arr[i];
                }
                delete[] arr;
                arr = temp;
            }
            for (int i=size; i>position; i--) {
                arr[i] = arr[i-1];
            }
            arr[position] = element;
            size++;
        }
        void remove(int position) {
            if (position < 0 || position >= size) {
                cout << "Invalid position" << endl;
                return;
            }
            for (int i=position; i<size-1; i++) {
                arr[i] = arr[i+1];
            }
            size--;
        }
        void display(){
            cout << "List elements are: ";
            for (int i=0; i<size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    ArrayList list;
    cout << "At begining:" << endl;
    list.display();
    cout << "After adding elements:" << endl;
    list.insert(10, 0);
    list.insert(20, 1);
    list.insert(30, 2);
    list.insert(40, 3);
    list.display();
    cout << "After removing elements:" << endl;
    list.remove(2);
    list.display();
    return 0;
}