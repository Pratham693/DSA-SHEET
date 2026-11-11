#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
int width_of_binary_tree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    long long ans = 0;
    queue<pair<Node *, long long>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        int size = q.size();
        long long first = q.front().second;
        long long last = q.front().second;

        for (int i = 0; i < size; i++)
        {
            auto current = q.front();
            Node *node = current.first;
            long long curPos = current.second;
            q.pop();

            if (i == 0)
            {
                first = curPos;
            }

            last = curPos;

            if (node->left)
            {
                q.push({node->left, 2 * curPos + 1});
            }
            if (node->right)
            {
                q.push({node->right, 2 * curPos + 2});
            }
        }

        ans = max(ans, last - first + 1);
    }

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
    cout << width_of_binary_tree(root);
    return 0;
}