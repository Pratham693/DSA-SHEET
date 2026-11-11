#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Count Number Of Subarray With Given XOR K
// Brute Force
// Time Complixty -> O(n^3) & Space Complixity -> O(1)
int subarray(vector<int> arr, int target)
{
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {

        for (int j = i; j < arr.size(); j++)
        {
            int XOR = 0;
            for (int k = i; k <= j; k++)
            {
                XOR ^= arr[k];
            }
            if (XOR == target)
                count++;
        }
    }

    return count;
}
// Better Version
// Time Complixty -> O(n^2) & Space Complixity -> O(1)

int subarray2(vector<int> arr, int target)
{

    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int XOR = 0;
        for (int j = i; j < arr.size(); j++)
        {

            XOR ^= arr[j];
            if (XOR == target)
            {
                count++;
            }
        }
    }

    return count;
}
// Optimal Version
// Time Complixty -> O(n) & Space Complixity -> O(n logn)
int subarray3(vector<int> arr, int target)
{
    int count = 0;
    int xr = 0;
    map<int, int> mpp;
    mpp[xr]++;
    for (int i = 0; i < arr.size(); i++)
    {
        xr = xr ^ arr[i];
        int x = xr ^ target;
        count += mpp[x];
        mpp[xr]++;
    }
    return count;
}

int main()
{
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;
    cout << subarray2(arr, 6) << endl;
    cout << subarray(arr, 6) << endl;
    cout << subarray3(arr, 6) << endl;

    return 0;
}