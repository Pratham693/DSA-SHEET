#include <iostream>
using namespace std;

class Node
{
public:
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

bool isChildrenSum(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    int sum = 0;
    if (root->left)
    {
        sum += root->left->data;
    }
    if (root->right)
    {
        sum += root->right->data;
    }
    return (root->data = sum && isChildrenSum(root->left) && isChildrenSum(root->right));
}

int main()
{

    Node *root = new Node(10);

    root->left = new Node(4);
    root->right = new Node(6);

    root->left->left = new Node(2);
    root->left->right = new Node(2);

    if (isChildrenSum(root))
        cout << "Tree satisfies Children Sum Property";
    else
        cout << "Tree does not satisfy Children Sum Property";

    return 0;
}