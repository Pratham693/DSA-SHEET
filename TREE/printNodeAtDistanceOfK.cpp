#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
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
void BuildParentMap(Node *root, unordered_map<Node *, Node *> &parent)
{
    if (root == NULL)
        return;

    queue<Node *> nodes;
    nodes.push(root);
    parent[root] = NULL;

    while (!nodes.empty())
    {
        Node *current = nodes.front();
        nodes.pop();

        if (current->left != NULL)
        {
            parent[current->left] = current;
            nodes.push(current->left);
        }
        if (current->right != NULL)
        {
            parent[current->right] = current;
            nodes.push(current->right);
        }
    }
}
vector<int> NodesAtKDistance(Node *root, Node *target, int k)
{
    unordered_map<Node *, Node *> parent;
    parent[root] = nullptr;

    BuildParentMap(root, parent);
    queue<Node *> q;

    unordered_set<Node *> visited;
    q.push(target);

    visited.insert(target);
    int current_distance = 0;
    while (!q.empty())
    {
        if (current_distance == k)
            break;
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            auto curr = q.front();
            q.pop();
            if (curr->left && !visited.count(curr->left))
            {
                q.push(curr->left);
                visited.insert(curr->left);
            }

            if (curr->right && !visited.count(curr->right))
            {
                q.push(curr->right);
                visited.insert(curr->right);
            }
            if (parent[curr] && !visited.count(parent[curr]))
            {
                q.push(parent[curr]);
                visited.insert(parent[curr]);
            }
        }
        current_distance++;
    }
    vector<int> result;
    while (!q.empty())
    {
        result.push_back(q.front()->data);
        q.pop();
    }
    return result;
}
int main()
{
    Node *root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);
    Node *target = root->left; 
    int k = 2;

    vector<int> ans = NodesAtKDistance(root, target, k);

    cout << "Nodes at distance " << k << " from " << target->data << ": ";
    for (int x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}