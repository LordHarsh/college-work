#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};
class DoublyLinkedList
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    void insertAtStart(int data)
    {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void insertAtEnd(int data)
    {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void insertAtPos(int data, int pos)
    {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            Node *temp = head;
            for (int i = 0; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next->prev = newNode;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
    void deleteAtStart()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
        }
    }
    void deleteAtEnd()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
        }
    }
    void deleteAtPos(int pos)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *temp = head;
            for (int i = 0; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            Node *temp2 = temp->next;
            temp->next = temp2->next;
            temp2->next->prev = temp;
            delete temp2;
        }
    }
    void search(int value)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *temp = head;
            int pos = 0;
            while (temp != NULL)
            {
                if (temp->data == value)
                {
                    cout << "Found at position " << pos << endl;
                    return;
                }
                temp = temp->next;
                pos++;
            }
            cout << "Not found" << endl;
        }
    }
    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    void menu()
    {
        int choice, data, pos;
        while (true)
        {
            cout << "1. Insert at start" << endl;
            cout << "2. Insert at end" << endl;
            cout << "3. Insert at position" << endl;
            cout << "4. Delete at start" << endl;
            cout << "5. Delete at end" << endl;
            cout << "6. Delete at position" << endl;
            cout << "7. Search" << endl;
            cout << "8. Display" << endl;
            cout << "9. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                insertAtStart(data);
                break;
            case 2:
                cout << "Enter data: ";
                cin >> data;
                insertAtEnd(data);
                break;
            case 3:
                cout << "Enter data: ";
                cin >> data;
                cout << "Enter position: ";
                cin >> pos;
                insertAtPos(data, pos);
                break;
            case 4:
                deleteAtStart();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> pos;
                deleteAtPos(pos);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> data;
                search(data);
                break;
            case 8:
                display();
                break;
            case 9:
                exit(0);
            default:
                cout << "Invalid choice" << endl;
            }
        }
    }
};
int main()
{
    DoublyLinkedList list;
    list.menu();
    return 0;
}