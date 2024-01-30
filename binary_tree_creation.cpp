#include <iostream>
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
int main()
{

    node *root;
    buildTree(root);
    return 0;
}