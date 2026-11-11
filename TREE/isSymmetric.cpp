#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool isSymmetricHelp(Node *left, Node *right)
{
    if (left == nullptr && right == nullptr)
    {
        return true;
    }
    if (left == nullptr || right == nullptr)
    {
        return false;
    }
    if (left->data != right->data)
    {
        return false;
    }

    return isSymmetricHelp(left->left, right->right) &&
           isSymmetricHelp(left->right, right->left);
}

bool isSymmetric(Node *root)
{
    if (root == nullptr)
    {
        return true;
    }
    return isSymmetricHelp(root->left, root->right);
}

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(2);

    root->left->left = new Node(3);
    root->left->right = new Node(4);

    root->right->left = new Node(4);
    root->right->right = new Node(3);

    cout << (isSymmetric(root) ? "Symmetric" : "Not symmetric") << endl;
    return 0;
}