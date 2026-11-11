#include <iostream>
#include <bits/stdc++.h>
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

// Zig - Zag Traversal
vector<vector<int>> ZigZag_Traversal(Node *root)
{
    vector<vector<int>> result;
    if (root == NULL)
    {
        return result;
    }

    queue<Node *> nodesQueue;
    nodesQueue.push(root);
    bool leftToRight = true;

    while (!nodesQueue.empty())
    {
        int size = nodesQueue.size();
        vector<int> row(size);

        for (int i = 0; i < size; i++)
        {
            Node *node = nodesQueue.front();
            nodesQueue.pop();

            int index = leftToRight ? i : size - 1 - i;
            row[index] = node->data;

            if (node->left != NULL)
            {
                nodesQueue.push(node->left);
            }
            if (node->right != NULL)
            {
                nodesQueue.push(node->right);
            }
        }

        result.push_back(row);
        leftToRight = !leftToRight;
    }

    return result;
}

void printVectorOfVectors(const vector<vector<int>> &levels)
{
    for (const auto &level : levels)
    {
        for (int value : level)
        {
            cout << value << " ";
        }
        cout << endl;
    }
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

    vector<vector<int>> answer = ZigZag_Traversal(root);
    printVectorOfVectors(answer);

    return 0;
}