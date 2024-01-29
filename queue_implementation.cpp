#include <iostream>
using namespace std;

class queue
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    queue(int size)
    {
        this->size = size;
        arr = new int[size];
        rear = 0;
        front = 0;
    }

    void push(int data)
    {
        if (rear == size)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }

        cout << data << " pushed into the queue" << endl;
    }

    int pop()
    {

        int ans = arr[front];
        if (front == rear)
        {
            return -1;
        }
        else
        {
            // int ans = arr[front];
            arr[front] = -1;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
        }
        cout << ans << " popped out of the queue" << endl;
    }

    bool isEmpty()
    {
        if (front == rear)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int qfront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << "front element is " << arr[front] << endl;
            return arr[front];
        }
    }
};
int main()
{

    queue q(5);

    q.push(8);
    q.push(9);
    q.push(10);
    q.push(11);

    q.qfront();

    q.pop();

    q.qfront();

    if (q.isEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not empty" << endl;
    }
    return 0;
}