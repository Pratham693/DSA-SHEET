#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Pascale Array Problem
// Problem1 -> FInd The NCR
int functionNCR(int n, int c)
{
    int res = 1;
    for (int i = 0; i < c; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }

    return res;
}
// Problem2 -> Print The Element Of the nth row

int functionN(int n)
{
    int ans = 1;
    cout << ans << " ";
    for (int i = 1; i < n; i++)
    {
        ans = ans * (n - i);
        ans = ans / i;
        cout << ans << " ";
    }
}
// Problem3 -> Print The Pascal Triangle
vector<int> generateRow(int row)
{
    long long ans = 1;
    vector<int> ansrow;
    ansrow.push_back(1);
    for (int col = 1; col < row; col++)
    {
        ans = ans * (row - col);
        ans = ans / col;
        ansrow.push_back(ans);
    }
    return ansrow;
}
vector<vector<int>> pascleTriangle(int N)
{
    vector<vector<int>> ans;
    for (int i = 1; i <= N; i++)
    {
        ans.push_back(generateRow(i));
    }
    return ans;
}

int main()
{
    int n, c;
    cin >> n >> c;
    cout << functionNCR(n - 1, c - 1) << endl;
    functionN(n);
    vector<vector<int>> tmep = pascleTriangle(5);

    return 0;
}