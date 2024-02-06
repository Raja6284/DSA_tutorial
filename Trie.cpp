#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    char data;
    TreeNode *children[26];
    bool isTerminal;
    TreeNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TreeNode *root;
    Trie()
    {
        root = new TreeNode('\n');
    }
    void insertWord(TreeNode *root, string word)
    {
        // using recursion base case ;
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        // taking every word in small latter ;
        int index = word[0] - 'a';
        TreeNode *child;
        // there are two case to insert word into the trie 1) word is present 2) word is not present ;

        // first if the word is peresent into the trie
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else // word is not present into the trie so we have to insert;
        {
            child = new TreeNode(word[0]);
            root->children[index] = child;
        }

        // now further word will done by recursion
        insertWord(child, word.substr(1));
    }
    // insert word into the trie;
    void insert(string word)
    {
        insertWord(root, word);
        return;
    }

    bool searchword(TreeNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }
        int index = word[0] - 'a';
        TreeNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        { // not present;
            return false;
        }

        return searchword(child, word.substr(1)); // recursive call to further search;
    }
    bool ssearch(string word)
    {
        return searchword(root, word);
    }
};

int main()
{
    Trie *t = new Trie();

    // constrain here every word shoud be in cps letter ;

    t->insert("raja");
    if (t->ssearch("raja"))
        cout << "found" << endl;
    else
        cout << "not found " << endl;
    return 0;
}
