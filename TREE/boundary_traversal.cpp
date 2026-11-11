#include <iostream>
#include <vector>
#include <algorithm>
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

bool isLeaf(Node *root)
{
    return root->left == NULL && root->right == NULL;
}

void addLeftBoundary(Node *root, vector<int> &ans)
{
    Node *curr = root;

    while (curr != NULL)
    {
        if (!isLeaf(curr))
        {
            ans.push_back(curr->data);
        }

        if (curr->left != NULL)
        {
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }
}

void addLeaves(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }

    if (isLeaf(root))
    {
        ans.push_back(root->data);
        return;
    }

    addLeaves(root->left, ans);
    addLeaves(root->right, ans);
}

void addRightBoundary(Node *root, vector<int> &ans)
{
    Node *curr = root;
    vector<int> temp;

    while (curr != NULL)
    {
        if (!isLeaf(curr))
        {
            temp.push_back(curr->data);
        }

        if (curr->right != NULL)
        {
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }

    reverse(temp.begin(), temp.end());

    for (int value : temp)
    {
        ans.push_back(value);
    }
}

vector<int> boundaryTraversal(Node *root)
{
    vector<int> ans;

    if (root == NULL)
    {
        return ans;
    }

    if (!isLeaf(root))
    {
        ans.push_back(root->data);
    }

    addLeftBoundary(root->left, ans);

    addLeaves(root, ans);

    addRightBoundary(root->right, ans);

    return ans;
}

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->left->right->left = new Node(8);
    root->right->right->right = new Node(9);

    vector<int> ans = boundaryTraversal(root);

    for (int value : ans)
    {
        cout << value << " ";
    }

    return 0;
}