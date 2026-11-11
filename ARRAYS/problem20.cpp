#include <iostream>
#include <map>
#include <bits/stdc++.h>
using namespace std;
// Two Sum Problem
// brute force
// Time Complexity = O(n^2)
void twosum(int arr[], int n, int key)
{
    int flag = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = arr[i] + arr[j];
            if (key == sum && i != j)
            {
                flag = 1;

                cout << i << " " << j << endl;
            }
        }
    }
    if (flag == 0)
    {
        cout << "No Element found in the Array" << endl;
    }
}
// better
// Time Complexity O(n X log n)
void twosum1(int arr[], int n, int key)
{
    map<int, int> mp1;

    for (int i = 0; i < n; i++)
    {
        int a = arr[i];
        int more = key - a;
        if (mp1.find(more) != mp1.end())
        {
            cout << mp1[more] << "," << i;
        }
        mp1[a] = i;
    }
    return;
}
// optimal
void twosum2(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == target)
        {
            cout << left << "," << right << endl;
            break;
            
        }
        else if (sum > target)
        {
            right--;
        }
        else
        {
            left++;
        }
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    // twosum(arr, 5, 4);
    // twosum1(arr, 5, 4);
    twosum2(arr, 5, 4);
    return 0;
}