#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
Node *FindInBST(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    else if (root->data > key)
    {
        return FindInBST(root->left, key);
    }
    else
    {
        return FindInBST(root->right, key);
    }
}
int main()
{
    Node *root = new Node(50);

    root->left = new Node(30);
    root->right = new Node(70);

    root->left->left = new Node(20);
    root->left->right = new Node(40);

    root->right->left = new Node(60);
    root->right->right = new Node(80);
    if (FindInBST(root, 70))
    {
        cout << "Value Is Present in BST Tree";
    }
    else
    {
        cout << "It is not Present in BST Tree";
    }

    return 0;
}