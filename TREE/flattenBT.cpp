#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void flatten(Node* root)
{
    Node* curr = root;

    while (curr != NULL)
    {
        if (curr->left != NULL)
        {
            Node* prev = curr->left;

            while (prev->right != NULL)
            {
                prev = prev->right;
            }

            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }

        curr = curr->right;
    }
}

void printList(Node* root)
{
    while (root != NULL)
    {
        cout << root->data << " ";
        root = root->right;
    }
}

int main()
{
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(5);

    root->left->left = new Node(3);
    root->left->right = new Node(4);

    root->right->right = new Node(6);

    flatten(root);

    cout << "Flattened Linked List: ";
    printList(root);

    return 0;
}