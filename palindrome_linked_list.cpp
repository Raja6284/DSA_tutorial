#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <vector>
using namespace std;

class node
{

public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(node *&head, int data)
{
    if (head == NULL)
    {
        node *temp = new node(data);
        head = temp;
    }

    node *toInsert = new node(data);
    toInsert->next = NULL;
    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = toInsert;
    
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

bool check_palindrom(vector<int>& arr){
    int s = 0; 
    int e = arr.size()-1;

    while(s<=e){
        if(arr[s] != arr[e]){
            return 0;
            break;
        }
        s++;
        e--;
    }

    return 1;
}


int main()
{

    node *head = new node(4);
    cout<<head->data<<endl;
    cout<<head->next<<endl;


    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtTail(head, 7);
    insertAtTail(head, 6);
    insertAtTail(head, 5);
    insertAtTail(head, 4);
    print(head);

    vector<int> arr;

    node* temp = head; 
    while(temp != NULL){
        arr.push_back(temp->data);
        temp = temp->next;
    }

    int ans = check_palindrom(arr);
    
    if(ans == 1){
        cout<<"This is palindrome"<<endl;
    }
    else{
        cout<<"Not palindrome"<<endl;
    }
    
    return 0;
}