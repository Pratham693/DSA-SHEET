#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Merge Sorted Arrays Without Extra Space
// Brute Force
// Time Complixty -> O(2(n+m)) & Space Complixity -> O(n+m)
void mergesort(int arr1[], int arr2[], int n, int m)
{
    int arr3[n + m];
    int left = 0, right = 0;
    int index = 0;
    while (left < n && right < m)
    {
        if (arr1[left] <= arr2[right])
        {
            arr3[index++] = arr1[left++];
        }
        else
        {
            arr3[index++] = arr2[right++];
        }
    }
    while (left < n)
    {
        arr3[index++] = arr1[left++];
    }
    while (right < m)
    {
        arr3[index++] = arr2[right++];
    }

    index = 0;
    for (int i = 0; i < n + m; i++)
    {
        if (i < n)
        {
            arr1[i] = arr3[i];
        }
        else
        {
            arr2[i - n] = arr3[i];
        }
    }
}

// optimal-1 Version
// Time Complixty -> O(min(n,m) + 2(nlogn)) & Space Complixity -> O(1)
void mergesort2array(int arr1[], int arr2[], int n, int m)
{
    int left = n - 1;
    int right = 0;
    while (left >= 0 && right < m)
    {
        if (arr1[left] > arr2[right])
        {
            swap(arr1[left], arr2[right]);
            left--, right++;
        }
        else
        {
            break;
        }
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}
int main()
{
    int arr[4] = {1, 3, 5, 7};
    int arr2[5] = {0, 2, 6, 8, 9};
    mergesort2array(arr, arr2, 4, 5);
    for (int i = 0; i < 4; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr2[i] << ", ";
    }

    return 0;
}