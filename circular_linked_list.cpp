#include <iostream>
using namespace std;

// we do not use head in this case, we deal with tail
class node
{

public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = next;
    }
};

// isnert data after the given element in linked list

void insert(node *&tail, int element, int value)
{

    // when circular linked list is empty
    if (tail == NULL)
    {
        node *temp = new node(value);
        tail = temp;
        temp->next = temp;
    }

    // non empty list
    // assuming that the element is present in the circular linked list

    node *current = tail;
    while (current->data != element)
    {
        current = current->next;
    }

    // if element is found, than current is representing current wala element

    node *temp = new node(value);
    if (temp->next = temp)
    {
        node *forward = current->next;
        current->next = temp;
        temp->next = forward;
    }
    else
    {
        temp->next = current->next;
        current->next = temp;
    }
}

void deletion(node* &tail, int value){
    
    //empty list
    if(tail == NULL){
        cout<<"list is empty, please check again "<<endl;
        return;
    }
    else{
        //non empty list , assuming that the value is present in the list
        node* back = tail;
        node* current = back->next;
        while(current->data != value){
            back = current; 
            current = current->next;
        }

        if(current == back){
            tail = NULL;
            return;
        }
        if(tail == current){
            tail = back;
            return;
        }
        
        back->next = current->next;
        current->next = NULL;
        delete current;
    }
}

void print(node* &tail)
{
    node *temp = tail;

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}
int main()
{

    node *tail = new node(8);
    cout << tail->data;

    insert(tail, 8, 9);
    print(tail);

    insert(tail, 8, 15);
    print(tail);
    return 0;
}