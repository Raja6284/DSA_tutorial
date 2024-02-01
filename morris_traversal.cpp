#include <bits/stdc++.h>
using namespace std;

class node {

public:
    int data;
    node* left;
    node* right;

    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BinaryTree {
public:

    node* root;

    BinaryTree() {
        root = NULL;
    }

    void MorrisTraversal() {
        node *current, *pre;

        if (root == NULL)
            return;

        current = root;
        while (current != NULL) {

            if (current->left == NULL) {
                cout << current->data << " ";
                current = current->right;
            }
            else {
                pre = current->left;
                while (pre->right != NULL && pre->right != current)
                    pre = pre->right;

                if (pre->right == NULL) {
                    pre->right = current;
                    current = current->left;
                }
                else {
                    pre->right = NULL;
                    cout << current->data << " ";
                    current = current->right;
                }
            }
        }
    }
};

int main() {
    
    BinaryTree tree;
    tree.root = new node(1);
    tree.root->left = new node(2);
    tree.root->right = new node(3);
    tree.root->left->left = new node(4);
    tree.root->left->right = new node(5);

    tree.MorrisTraversal();

    return 0;
}
