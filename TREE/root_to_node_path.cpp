#include <iostream>
#include <vector>
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

bool RootToNodePath(Node *root, int target, vector<int> &path)
{
    if (root == NULL)
    {
        return false;
    }

    path.push_back(root->data);
    if (root->data == target)
    {
        return true;
    }
    if (RootToNodePath(root->left, target, path) || RootToNodePath(root->right, target, path))
    {
        return true;
    }

    path.pop_back();
    return false;
}
int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int target = 5;

    vector<int> path;

    RootToNodePath(root, target, path);

    for (int value : path)
    {
        cout << value << " ";
    }

    return 0;
}