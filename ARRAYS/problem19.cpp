#include <iostream>
#include <map>
#include <bits/stdc++.h>
using namespace std;
// longest subarray which sum is k
// Brute Force method Time Complexity - O(n^2);

int subarray(int arr[], int n, int key)
{
    int sum;
    int maxlength = 0;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == key)
            {
                int length = j - i + 1;
                maxlength = max(maxlength, length);
            }
        }
    }
    return maxlength;
}
// Better
int subarray2(int arr[], int n, int key)
{
    map<int, int> preSumMap;
    int sum = 0;
    int maxlength = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == key)
        {
            maxlength = max(maxlength, i + 1);
        }
        int rem = sum - key;
        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxlength = max(maxlength, len);
        }
        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }
    return maxlength;
}
// Optimal
int subarray3(int arr[], int n, int key)
{
    int left = 0, right = 0;
    int maxlength = 0;
    int sum = arr[0];
    while (right < n)
    {
        while (left <= right && sum > key)
        {
            sum -= arr[left];
            left++;
        }
        if (sum == key)
        {
            maxlength = max(maxlength, right - left + 1);
        }
        right++;
        if (right < n)
        {
            sum += arr[right];
        }
    }
    return maxlength;
}
int main()
{
    int n[] = {1, 0, 0, 1, 1, 1, 2};
    // cout << subarray(n, 7, 3);
    cout << subarray3(n, 7, 3);

    return 0;
}