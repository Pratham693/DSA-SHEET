#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Count Number Of Subarrays which Sums Equals To The K
// Brute Force -> Time complixty = O(n^3) & Space Complexity = O(1)
int subarray(int arr[], int n, int k)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int l = i; l <= j; l++)
            {
                sum = sum + arr[l];
            }
            if (sum == k)
            {
                count++;
            }
        }
    }
    return count;
}
// Better Version ->  Time complixty = O(n^2) & Space Complexity = O(1)
int subarray2(int arr[], int n, int k)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == k)
            {
                count++;
            }
        }
    }
    return count;
}
// Optimal Version Time Complixty - O(n) & Space Complexity O(n); 
int subarray3(int arr[], int n, int k)
{
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    int preSum = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        preSum += arr[i];
        int remove = preSum - k;
        count += mpp[remove];
        mpp[preSum] += 1;
    }
    return count;
}
main()
{
    int arr[] = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    cout << subarray(arr, 10, 3);
    cout << endl;
    cout << subarray2(arr, 10, 3);
    cout << endl;
    cout << subarray3(arr, 10, 3);

    return 0;
}