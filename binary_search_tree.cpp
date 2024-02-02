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

node *insert_bst(node *root, int d)
{

    if (root == NULL)
    {
        root = new node(d);
        return root;
    }

    if (root->data > d)
    {
        // insert in left sub tree
        root->left = insert_bst(root->left, d);
    }
    else
    {
        // insert in right sub tree
        root->right = insert_bst(root->right, d);
    }

    return root;
}

void levelOrderTraversal(node *&root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        { // old level has been completely traversed
            cout << endl;

            if (!q.empty())
            { // queue still has some child node
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

void insert_data(node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insert_bst(root, data);
        cin >> data;
    }
}

int main()
{

    node *root = NULL;

    cout << "Enter the data to insert in BST:" << endl;
    insert_data(root);

    cout << "Printing the BST:" << endl;
    levelOrderTraversal(root);

    return 0;
}