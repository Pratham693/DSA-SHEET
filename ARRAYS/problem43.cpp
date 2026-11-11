#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Optimal Solution
// Time Complixity -> O(NlogN) & Space Complixity -> O(N)
long long merge_count(vector<int> &arr, int l, int mid, int r)
{
    vector<int> temp;
    int i = l, j = mid + 1;
    long long count = 0;

    while (i <= mid && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            count += (mid - i + 1);
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]); 
        i++;
    }
    while (j <= r)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int k = l; k <= r; k++)
        arr[k] = temp[k - l];

    return count;
}

long long merge_sort(vector<int> &arr, int l, int r)
{
    long long count = 0;
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        count += merge_sort(arr, l, mid);
        count += merge_sort(arr, mid + 1, r);
        count += merge_count(arr, l, mid, r);
    }
    return count;
}

int main()
{
    vector<int> arr = {5, 3, 2, 4, 1};
    long long total = merge_sort(arr, 0, arr.size() - 1);
    cout << "Total Inversions: " << total << endl;
    return 0;
}