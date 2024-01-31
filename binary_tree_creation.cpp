#include <iostream>
#include <queue>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    int data;
    cout << "Enter the data" << endl;
    cin >> data;

    root = new node(data);

    if (data == -1)
    { // setting condition for leaf node
        return NULL;
    }

    cout << "Enter data to insert at the left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter data to insert at the right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(node* root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {   //old level has been completely traversed
            cout << endl;

            if (!q.empty())
            {   //queue still has some child node
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}


int main()
{
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    node *root;
    buildTree(root);

    levelOrderTraversal(root);
    return 0;
}