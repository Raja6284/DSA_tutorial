#include <iostream>
using namespace std;

class stack
{

public:
    int *arr;
    int top;
    int size;

    stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int data)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = data;
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack Underflow" << endl;
        }
    }

    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    bool empty()
    {
        if (top == -1)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
};

int main()
{

    stack st(8);
     //cout<<st.peek();  // garbage value will be present initially

    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);
    st.push(9);

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    if (st.empty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }
    return 0;
}