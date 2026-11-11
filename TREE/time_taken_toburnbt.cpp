#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* markParents(Node* root, unordered_map<Node*, Node*>& parent, int target) {
    queue<Node*> q;
    q.push(root);

    Node* targetNode = NULL;

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr->data == target) {
            targetNode = curr;
        }

        if (curr->left) {
            parent[curr->left] = curr;
            q.push(curr->left);
        }

        if (curr->right) {
            parent[curr->right] = curr;
            q.push(curr->right);
        }
    }

    return targetNode;
}

int burnTree(Node* root, int target) {
    if (root == NULL) {
        return 0;
    }

    unordered_map<Node*, Node*> parent;
    Node* targetNode = markParents(root, parent, target);

    if (targetNode == NULL) {
        return 0;
    }

    unordered_set<Node*> visited;
    queue<Node*> q;

    q.push(targetNode);
    visited.insert(targetNode);

    int time = 0;

    while (!q.empty()) {
        int size = q.size();
        bool burnedNewNode = false;

        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();

            if (curr->left && !visited.count(curr->left)) {
                q.push(curr->left);
                visited.insert(curr->left);
                burnedNewNode = true;
            }

            if (curr->right && !visited.count(curr->right)) {
                q.push(curr->right);
                visited.insert(curr->right);
                burnedNewNode = true;
            }

            if (parent.count(curr) && !visited.count(parent[curr])) {
                q.push(parent[curr]);
                visited.insert(parent[curr]);
                burnedNewNode = true;
            }
        }

        if (burnedNewNode) {
            time++;
        }
    }

    return time;
}

int main() {
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);

    root->right->right = new Node(6);
    root->right->right->left = new Node(9);

    int target = 8;

    cout << burnTree(root, target);

    return 0;
}