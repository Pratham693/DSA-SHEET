#include <iostream>
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

int floorinBST(Node *root, int key)
{
    int floor = -1;
    Node *temp = root;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return temp->data;
        }
        else if (temp->data < key)
        {
            floor = temp->data;
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }

    return floor;
}

int main()
{
    Node *root = new Node(50);

    root->left = new Node(30);
    root->right = new Node(70);

    root->left->left = new Node(20);
    root->left->right = new Node(40);

    root->right->left = new Node(60);
    root->right->right = new Node(80);

    int key = 30;
    cout << "The Floor of key = " << key << " is " << floorinBST(root, key);

    return 0;
}