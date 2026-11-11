#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print2darray(int arr[][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << ", ";
        }
        cout << endl;
    }
}
// Brute Force Solution
// Time Complexity -> O(n^2) & Space Complexity -> O(n^2)
void rotate90degree(int arr[4][4], int ans[4][4])
{

    int n = 4;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            ans[j][n - i - 1] = arr[i][j];
        }
    }
}
// Optimal Version
// Time Complexity -> O(n^2) & Space Complexity -> O(1);
void rotate90degree2(int arr[4][4])
{
    int n = 4;
    // Transpose Of Matrix
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        reverse(arr[i], arr[i] + n);
    }
}
int main()
{
    int arr[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    print2darray(arr);
    cout << endl;
    rotate90degree2(arr);
    print2darray(arr);

    return 0;
}