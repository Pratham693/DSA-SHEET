#include <iostream>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    string serialize(Node *root)
    {
        if (root == NULL)
            return "";

        string s = "";
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();

            if (node == NULL)
            {
                s += "#,";
            }
            else
            {
                s += to_string(node->data) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }

        return s;
    }

    Node *deserialize(string data)
    {
        if (data.empty())
            return NULL;

        stringstream ss(data);
        string str;

        getline(ss, str, ',');

        Node *root = new Node(stoi(str));
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();

            getline(ss, str, ',');
            if (str != "#")
            {
                Node *leftNode = new Node(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(ss, str, ',');
            if (str != "#")
            {
                Node *rightNode = new Node(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }

    void inorder(Node *root)
    {
        if (root == NULL)
            return;

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    Solution obj;

    string serialized = obj.serialize(root);
    cout << "Serialized Tree: " << serialized << endl;

    Node *newRoot = obj.deserialize(serialized);

    cout << "Inorder Traversal after Deserialization: ";
    obj.inorder(newRoot);
    cout << endl;

    return 0;
}
