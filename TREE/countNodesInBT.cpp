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

int countNode(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + countNode(root->left) + countNode(root->right);
}

int main()
{
    Node *root = new Node(3);

    root->left = new Node(5);
    root->right = new Node(1);

    root->left->left = new Node(6);
    root->left->right = new Node(2);

    root->right->left = new Node(0);
    root->right->right = new Node(8);

    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    cout << "Total Nodes: " << countNode(root) << endl;

    return 0;
}