#include <iostream>
#include <vector>
#include <map>
#include <queue>
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

vector<vector<int>> VerticalOrder(Node *root)
{
    vector<vector<int>> result;

    if (root == NULL)
        return result;

    map<int, vector<int>> nodes;
    queue<pair<Node *, int>> q;

    q.push({root, 0});

    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();

        Node *node = temp.first;
        int hd = temp.second;

        nodes[hd].push_back(node->data);

        if (node->left != NULL)
            q.push({node->left, hd - 1});

        if (node->right != NULL)
            q.push({node->right, hd + 1});
    }

    for (auto it : nodes)
    {
        result.push_back(it.second);
    }

    return result;
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

    vector<vector<int>> ans = VerticalOrder(root);

    cout << "Vertical Order Traversal:\n";
    for (const auto &col : ans)
    {
        for (int value : col)
            cout << value << " ";
        cout << endl;
    }

    return 0;
}