#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

vector<int> topView(Node* root)
{
    vector<int> ans;

    if (root == NULL)
        return ans;

    map<int, int> top;
    queue<pair<Node*, int>> q;

    q.push({root, 0});

    while (!q.empty())
    {
        Node* node = q.front().first;
        int hd = q.front().second;

        q.pop();

        if (top.find(hd) == top.end())
        {
            top[hd] = node->data;
        }

        if (node->left)
        {
            q.push({node->left, hd - 1});
        }

        if (node->right)
        {
            q.push({node->right, hd + 1});
        }
    }

    for (auto x : top)
    {
        ans.push_back(x.second);
    }

    return ans;
}

int main()
{
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->right = new Node(4);
    root->right->right = new Node(5);

    vector<int> ans = topView(root);

    cout << "Top View: ";

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}