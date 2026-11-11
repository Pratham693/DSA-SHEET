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

Node *insertIntoBST(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }

    if (val < root->data)
    {
        root->left = insertIntoBST(root->left, val);
    }
    else
    {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = NULL;

    root = insertIntoBST(root, 8);
    insertIntoBST(root, 4);
    insertIntoBST(root, 12);
    insertIntoBST(root, 2);
    insertIntoBST(root, 6);
    insertIntoBST(root, 10);
    insertIntoBST(root, 14);

    cout << "Inorder Traversal: ";
    inorder(root);

    return 0;
}
