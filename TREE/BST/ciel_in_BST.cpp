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
int CielFindInBST(Node *root, int key, int &ceil)
{
    if (root == NULL)
    {
        return ceil;
    }

    if (root->data > key)
    {
        ceil = root->data;
        return CielFindInBST(root->left, key, ceil);
    }
    else
    {
        return CielFindInBST(root->right, key, ceil);
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
    int ceil = -1;
    cout << CielFindInBST(root, 30, ceil);

    return 0;
}