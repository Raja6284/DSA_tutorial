#include <bits/stdc++.h>
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
bool isBst(node* root, long long mini,long long maxi){
        if(root == NULL){
            return true;
        }
        
        if((root->data > mini) && (root->data < maxi)){
            bool left = isBst(root->left, mini, root->data);
            bool right = isBst(root->right, root->data, maxi);
            
            return left&&right;
        }
        else
            return false;
        
    }
    
    bool isValidBST(node* root) {
        if(root == NULL){
            return true;
        }
        
        if((root->left==NULL && root->right==NULL)){
             return true;
        }
           
        
        int mini = INT_MIN;
        int maxi = INT_MAX;
        
        return isBst(root,mini, maxi);
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

    if(isValidBST(root)){
        cout<<"This is valid BST"<<endl;
    }
    else{
        cout<<"This is not a valid BST"<<endl;
    }
    return 0;
}