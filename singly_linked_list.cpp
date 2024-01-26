#include <iostream>
using namespace std;

class node
{

public:
    int data;
    node *next;

    node(int data)
    { // this is constructor
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(node *&head, int value)
{
    node *temp = new node(value);

    temp->next = head;
    head = temp;
}

void inserAtTail(node *&head, int value)
{
    node *temp = new node(value);

    node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = temp;
}

void insertAtanyPos(node *head, int value, int position)
{
    node *temp = new node(value);
    int count = 1;

    if (position == 1)
    {
        insertAtHead(head, value);
    }

    node *current = head;
    while (count < position - 1)
    {
        current = current->next;
        count++;
    }

    if (current->next == NULL)
    {
        inserAtTail(head, value);
    }
    else
    {
        temp->next = current->next;
        current->next = temp;
    }
}

void print(node *&head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void deleteAtHead(node *&head)
{
    node *temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
}

void deleteAtTail(node *&head)
{
    node *temp = head;
    node *current = NULL;

    while (temp->next != NULL)
    {
        current = temp;
        temp = temp->next;
    }

    current->next = temp->next;
    delete temp;
}

void deleteAtanyPos(node *&head, int position)
{
    node *temp = head;
    node *current = NULL;
    int count = 1;

    if (position == 1)
    {
        deleteAtHead(head);
    }

    while (count < position)
    {
        current = temp;
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL)
    {
        deleteAtTail(head);
    }
    else
    {
        current->next = temp->next;
        temp->next = NULL;
        delete temp;
    }
}

int main()
{

    node *head = new node(50);
    // cout<<head->data<<endl;
    // cout<<head->next<<endl;

    insertAtHead(head, 49);
    insertAtHead(head, 48);
    insertAtHead(head, 47);
    insertAtHead(head, 46);

    // print(head);
    // cout<<endl;

    inserAtTail(head, 51);
    inserAtTail(head, 52);
    inserAtTail(head, 53);
    inserAtTail(head, 54);

    // print(head);
    // cout<<endl;

    insertAtanyPos(head, 500, 3);

    print(head);
    cout << endl;

    insertAtanyPos(head, 500, 11);

    print(head);
    cout << endl;

    deleteAtHead(head);
    print(head);
    cout << endl;

    deleteAtTail(head);
    print(head);
    cout << endl;

    deleteAtanyPos(head, 5);
    print(head);
    cout << endl;

    deleteAtanyPos(head, 8);
    print(head);
    cout << endl;

    return 0;
}