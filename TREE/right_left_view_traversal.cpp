#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

void leftViewUtil(Node* root, int level, int& maxLevel, vector<int>& res) {
    if (root == nullptr) return;

    if (level > maxLevel) {
        res.push_back(root->data);
        maxLevel = level;
    }

    leftViewUtil(root->left, level + 1, maxLevel, res);
    leftViewUtil(root->right, level + 1, maxLevel, res);
}

vector<int> leftView(Node* root) {
    vector<int> res;
    int maxLevel = -1;
    leftViewUtil(root, 0, maxLevel, res);
    return res;
}

void rightViewUtil(Node* root, int level, int& maxLevel, vector<int>& res) {
    if (root == nullptr) return;

    if (level > maxLevel) {
        res.push_back(root->data);
        maxLevel = level;
    }

    rightViewUtil(root->right, level + 1, maxLevel, res);
    rightViewUtil(root->left, level + 1, maxLevel, res);
}

vector<int> rightView(Node* root) {
    vector<int> res;
    int maxLevel = -1;
    rightViewUtil(root, 0, maxLevel, res);
    return res;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(5);

    vector<int> left = leftView(root);
    vector<int> right = rightView(root);

    cout << "Left view: ";
    for (int x : left) cout << x << " ";
    cout << endl;

    cout << "Right view: ";
    for (int x : right) cout << x << " ";
    cout << endl;

    return 0;
}