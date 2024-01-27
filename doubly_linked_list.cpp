#include <iostream>
using namespace std;

class node
{

public:
    int data;
    node *next;
    node *prev;

    // constructor
    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertAtHead(node *&head, int value)
{
    node *temp = new node(value);

    temp->next = head;
    head->prev = temp;
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
    temp->prev = current;
    current = temp;
}

void insertAtanyPos(node *&head, int value, int position)
{
    if (head == NULL)
    {
        node *temp = new node(value);
        head = temp;
    }

    if (position == 1)
    {
        insertAtHead(head, value);
        return;
    }
    else
    {
        int count = 1;
        node *temp = new node(value); // node to be inserted
        node *current = head;

        while (count < position - 1)
        {
            current = current->next;
            count++;
        }

        if (current->next == NULL)
        {
            inserAtTail(head, value);
            return;
        }
        else
        {
            temp->next = current->next;
            current->next->prev = temp;
            current->next = temp;
            temp->next->prev = current;
        }
    }
}

void deleteAtHead(node *&head)
{
    node *temp = head;

    temp->next->prev = NULL;
    head = temp->next;
    temp->next = NULL;
    delete temp;
}

void deleteAtTail(node *&head)
{
    node *temp = head;
    // node* back = NULL;
    while (temp->next != NULL)
    {
        // back = temp;
        temp = temp->next;
    }

    temp->prev->next = NULL;
    temp->prev = NULL;
    delete temp;
}

void deleteAtanyPos(node* &head, int position){
    
    if(position == 1){
        deleteAtHead(head);
        return;
    }
    
    node* current = head;
    node* back = NULL;
    int count = 1;

    while(count < position){
        back = current;
        current = current->next;
        count++;
    }
    if(current == NULL){
        deleteAtTail(head);
    }
    else{
        current->prev = NULL;
        back->next = current->next;
        current->next = NULL;
        delete current;
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
    cout << endl;
}
int main()
{

    node *node1 = new node(5);

    // cout << node1->data << endl;
    // cout << node1->next << endl;
    // cout << node1->prev << endl;

    node *head = node1;

    insertAtHead(head, 4);
    // print(head);

    insertAtHead(head, 3);
    // print(head);

    insertAtHead(head, 2);
    // print(head);

    inserAtTail(head, 6);
    // print(head);

    inserAtTail(head, 7);
    // print(head);

    inserAtTail(head, 8);
    // print(head);

    insertAtanyPos(head, 100, 1); // insertAtHead
    // print(head);

    insertAtanyPos(head, 101, 8);
    // print(head);

    insertAtanyPos(head, 105, 10); // insertAtTail
    // print(head);

    insertAtanyPos(head, 50, 5); // insert at 5th position
    print(head);

    deleteAtHead(head);
    print(head);

    deleteAtTail(head);
    print(head);

    deleteAtanyPos(head,1); //delete at head
    print(head);

    deleteAtanyPos(head,8); //delete at tail
    print(head);
    
    deleteAtanyPos(head,5); //delete at 5th position
    print(head);
}