#include <iostream>
#include <vector>
#include <unordered_map>
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

Node *BuildTree(vector<int> &preorder, int &preindex,
                int inorderstart, int inorderend, unordered_map<int, int> &mp)
{
    if (inorderstart > inorderend)
    {
        return NULL;
    }

    int rootVal = preorder[preindex++];
    Node *root = new Node(rootVal);
    int inorderindex = mp[rootVal];

    root->left = BuildTree(preorder, preindex, inorderstart, inorderindex - 1, mp);
    root->right = BuildTree(preorder, preindex, inorderindex + 1, inorderend, mp);

    return root;
}
Node *ConstructTree(vector<int> &preorder, vector<int> &inorder)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }
    int preindex = 0;
    return BuildTree(preorder, preindex, 0, inorder.size() - 1, mp);
}
void printInorder(Node *root)
{
    if (root == NULL)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

void printPreorder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main()
{
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};

    Node *root = ConstructTree(preorder, inorder);

    cout << "Inorder Traversal: ";
    printInorder(root);

    cout << "\nPreorder Traversal: ";
    printPreorder(root);

    return 0;
}