#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}
// Optimal Solution
// Time Complexity = O(n);
void zero_end(int arr[], int n)
{
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }

    for (int i = j + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
        else
        {
            arr[i] = 0;
        }
    }
}
int main()
{
    int arr[10] = {1, 2, 0, 0, 3, 4, 0, 5, 6, 8};
    print(arr, 10);
    zero_end(arr, 10);
    print(arr, 10);
    return 0;
}