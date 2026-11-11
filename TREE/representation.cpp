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

    PrintTree(root);

    return 0;
}