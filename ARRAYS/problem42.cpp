#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Brute Force Solution 
// Time Complixity -> O(n^2) & Space Complixity -> (1)
int count_inversion(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                count++;
        }
    }
    return count;
}

int main()
{
    int arr[] = {5, 3, 2, 4, 1};
    int n = 5;
    cout << "Total Inversions: " << count_inversion(arr, n) << endl;
    return 0;
}