#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Find The Smallest Divisor Given A ThreshHold
int SumByD(vector<int> &arr, int div)
{
    int sum = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        sum += ceil((double)arr[i] / div);
    }
    return sum;
}
int smallestDivisor(vector<int> &arr, int linit)
{
    int low = 1, high = *max_element(arr.begin(), arr.end());
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (SumByD(arr, mid) <= linit)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 8};
    cout << smallestDivisor(arr, 6);
    return 0;
}