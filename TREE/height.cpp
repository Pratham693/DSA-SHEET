#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};
int maxheight(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int lh = maxheight(root->left);
    int rh = maxheight(root->right);
    return 1 + max(lh, rh);
}

// Printing the Binary Search Tree
void PrintTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    PrintTree(root->left);

    cout << root->data << " ";

    PrintTree(root->right);
}

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);

    // PrintTree(root);
    cout << maxheight(root);

    return 0;
}