// Implementation of stack using linked list

#include <iostream>
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

class stack
{

public:
    node *head;
    int stack_size;

    stack()
    {
        head = NULL;
        stack_size = 0;
    }

    void push(int val)
    {
        node *temp = new node(val);
        temp->next = head;
        head = temp;

        cout << val << " pushed into the stack" << endl;
        stack_size++;
    }

    void pop()
    {
        if (head == NULL)
        {
            cout << "Stack is empty, cannot POP" << endl;
        }

        int popped = head->data;
        node *temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;

        cout << endl;
        cout << popped << " popped out of the stack" << endl;
        stack_size--;
    }

    int top()
    {
        if (head == NULL)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        cout << "top-element is " << head->data << endl;
        return head->data;
    }

    int size()
    {
        cout << "Size of the stack is " << stack_size << endl;
        return stack_size;
    }

    bool empty()
    {
        if (head == NULL)
        {
            cout << "Stack is empty" << endl;
            return 1;
        }
        cout << "Stack is not empty" << endl;
        return 0;
    }
};
int main()
{

    stack st;

    cout << st.top();
    cout << endl;

    cout << st.size();
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);
    st.push(9);

    cout << st.top();

    st.pop();
    cout << endl;

    cout << st.size();

    cout << st.empty();

    return 0;
}