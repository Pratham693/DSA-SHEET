#include <iostream>
#include <cmath>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

int checkBalance(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = checkBalance(root->left);

    if (lh == -1)
    {
        return -1;
    }

    int rh = checkBalance(root->right);

    if (rh == -1)
    {
        return -1;
    }

    if (abs(lh - rh) > 1)
    {
        return -1;
    }

    return 1 + max(lh, rh);
}

bool isBalanced(Node *root)
{
    return checkBalance(root) != -1;
}

int main()
{
    Node *root = new Node(10);

    root->left = new Node(5);
    root->right = new Node(15);

    root->left->left = new Node(2);
    root->left->right = new Node(7);

    root->right->left = new Node(12);

    if (isBalanced(root))
    {
        cout << "Tree is Balanced";
    }
    else
    {
        cout << "Tree is Not Balanced";
    }

    return 0;
}