#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

vector<int> bottomView(Node *root)
{
	vector<int> result;

	if (root == NULL)
		return result;

	map<int, int> bottom;
	queue<pair<Node *, int>> q;
	q.push({root, 0});

	while (!q.empty())
	{
		Node *node = q.front().first;
		int hd = q.front().second;
		q.pop();

		bottom[hd] = node->data;

		if (node->left != NULL)
			q.push({node->left, hd - 1});

		if (node->right != NULL)
			q.push({node->right, hd + 1});
	}

	for (auto column : bottom)
		result.push_back(column.second);

	return result;
}

int main()
{
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->right = new Node(4);
	root->right->right = new Node(5);

	vector<int> result = bottomView(root);

	cout << "Bottom View: ";
	for (int value : result)
		cout << value << " ";

	return 0;
}
