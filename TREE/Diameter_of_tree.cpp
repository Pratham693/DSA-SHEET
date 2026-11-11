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
        left = NULL;
        right = NULL;
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

void FindDiameter(Node *root, int &maxi)
{
    if (root == NULL)
    {
        return;
    }

    int lh = maxheight(root->left);
    int rh = maxheight(root->right);

    int currentDiameter = lh + rh + 2;

    maxi = max(maxi, currentDiameter);

    FindDiameter(root->left, maxi);
    FindDiameter(root->right, maxi);
}

int main()
{
    Node *root = new Node(10);

    root->left = new Node(5);
    root->right = new Node(15);

    root->left->left = new Node(2);
    root->left->right = new Node(7);

    root->right->left = new Node(12);

    int maxi = 0;

    FindDiameter(root, maxi);

    cout << "Diameter of Binary Tree: " << maxi;

    return 0;
}