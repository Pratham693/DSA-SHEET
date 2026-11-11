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

int maximum_sum_path(Node *node, int &maxi)
{
    if (node == NULL)
    {
        return 0;
    }

    int lsum = maximum_sum_path(node->left, maxi);
    int rsum = maximum_sum_path(node->right, maxi);

    maxi = max(maxi, lsum + rsum + node->data);

    return node->data + max(lsum, rsum);
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

    maximum_sum_path(root, maxi);

    cout << "Maximum Path Sum: " << maxi << endl;

    return 0;
}