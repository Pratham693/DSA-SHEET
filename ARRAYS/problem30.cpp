#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Spiral Traversal
void spiraltraversal(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();
    int left = 0, right = m - 1;
    int top = 0, bottom = n - 1;
    vector<int> ans;
    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            ans.push_back(mat[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(mat[i][right]);
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(mat[bottom][i]);
            }
        }
        bottom--;
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(mat[i][top]);
            }
        }
        left++;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << ", ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;
}

int main()
{
    vector<vector<int>> v1 = {{11, 12, 13, 14, 15}, {16, 19, 20, 30, 14}, {65, 39, 33, 29, 33}, {22, 33, 12, 15, 19}, {16, 19, 20, 30, 14}};
    spiraltraversal(v1);
    return 0;
}