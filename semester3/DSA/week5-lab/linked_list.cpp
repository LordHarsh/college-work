#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data=value;
        next=nullptr;
    }
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }

    void create(int value) {
        Node* ptr = new Node(value);
        if (!head) {
            head = ptr;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = ptr;
        }
    }

    void insertAtBeginning(int value) {
        Node* ptr= new Node(value);
        ptr->next = head;
        Node* temp=ptr;
        head = temp;
    }

    void insertAtEnd(int value) {
        Node* ptr= new Node(value);
        if (!head) {
            head = ptr;
        } else {
            Node* temp = head;
            while (temp->next!=NULL) {
                temp = temp->next;
            }
            temp->next =ptr;
        }
    }

    void insertAtMiddle(int value, int position) {
        Node* ptr= new Node(value);
        if (!head) {
            head =ptr;
        } else {
            Node* temp = head;
            for (int i=1; i < position && temp; i++) {
                temp = temp->next;
            }
            if (temp) {
                ptr->next = temp->next;
                temp->next =ptr;
            } else {
                cout<< "Invalid position."<<endl;
            }
        }
    }
 void deleteatbegin(){
    Node* temp = head;
    head = temp->next;
    delete temp;
}
void deleteMid(int value) {
    Node* temp = head;
    Node* temp1 = nullptr;

    while(temp != nullptr &&temp->data != value) {
        temp1 = temp;
        temp = temp->next;
    }
    /*if (temp == nullptr) {
        cout << "Value not found in the list." << endl;
        return;
    }*/
    if (temp1 == nullptr) {
        head = temp->next;
    } else {
        temp1->next = temp->next;
    }

    delete temp;
}

void deleteEnd() {
    Node* temp = head;
    Node* temp1=nullptr;
        while(temp->next!=NULL){
            temp1=temp;
            temp=temp->next;
        }
        temp1->next=nullptr;
            delete (temp);
}

    bool search(int value) {
        Node* temp = head;
        while (temp) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout <<endl;
    }
};

int main() {
    LinkedList list;
    int choice;

    while (true) {
        cout << "Choose an operation:\n"<< "1. Create\n2. Insert at Beginning\n3. Insert at End\n4. Insert at Middle\n"
                  << "5. Delete at Beginning\n"<< "6. Delete at middle\n"<< "7. Delete at end\n"<< "8. Search\n"<< "9. Display\n"<< "10. Exit\n"
                  << "Enter your choice: ";
        cin >> choice;
        int value;
        switch (choice) {
            case 1:{
              cout << "Enter value: ";
            cin >> value;
                list.create(value);
                list.display();
                break;
            }
            case 2: {
                cout << "Enter value: ";
                cin >> value;
                list.insertAtBeginning(value);
                list.display();
                break;
            }
            case 3: {
                cout << "Enter value: ";
                cin >> value;
                list.insertAtEnd(value);
                list.display();
                break;
            }
            case 4: {
                int position;
                cout << "Enter value: ";
                cin >> value;
                cout << "Enter index: ";
                cin >> position;
                list.insertAtMiddle(value, position);
                list.display();
                break;
            }
             case 5: {
                list.deleteatbegin();
                list.display();
                break;
            }
            case 6: {
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteMid(value);
                list.display();
                break;
            }
            case 7: {
                list.deleteEnd();
                list.display();
                break;
            }
            case 8: {
                cout << "Enter value to search: ";
                cin >> value;
                if (list.search(value)) {
                    cout << value << " found in the list." <<endl;
                } else {
                    cout << value << " not found in the list." <<endl;
                }
                break;
            }
            case 9: {
                cout << "Linked List: ";
                list.display();
                break;
            }
            case 10: {
                return 0;
            }
            default:
            cout << "Invalid choice. Please choose again." <<endl;
        }
    }

    return 0;
}