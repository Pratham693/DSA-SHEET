#include <iostream>
#include <stack>
using namespace std;
// Itrative_Traversal
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

void Itrative_PreOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *node = st.top();
        st.pop();
        cout << node->data << " ";
        if (node->right != NULL)
        {
            st.push(node->right);
        }
        if (node->left != NULL)
        {
            st.push(node->left);
        }
    }
}
void Itrative_InOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> st;
    Node *current = root;
    while (current != NULL || !st.empty())
    {
        while (current != NULL)
        {
            st.push(current);
            current = current->left;
        }
        current = st.top();
        st.pop();
        cout << current->data << " ";

        current = current->right;
    }
}
void Itravtive_Postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> st1;
    stack<Node *> st2;
    st1.push(root);
    while (!st1.empty())
    {
        Node *node = st1.top();
        st1.pop();

        st2.push(node);

        if (node->left != NULL)
            st1.push(node->left);

        if (node->right != NULL)
            st1.push(node->right);
    }
    while (!st2.empty())
    {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}
int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    Itrative_PreOrder(root);
    cout << endl;
    Itrative_InOrder(root);
    cout << endl;
    Itravtive_Postorder(root);

    return 0;
}