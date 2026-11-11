#include <iostream>
#include <vector>
using namespace std;
// Find The missing and Repeating Number
// Brute Force
// Time Complixity -> O(2n) & Space Complixity -> O(n)
void missing(int arr[], int n)
{
    // int count = 0;
    int hasmap[6] = {0};
    for (int i = 0; i < n; i++)
    {
        hasmap[arr[i]] += 1;
    }

    for (int i = 1; i < n; i++)
    {
        if (hasmap[i] == 0)
        {
            cout << "Missing Number " << i << endl;
        }
        else if (hasmap[i] > 1)
        {
            cout << "Repeating number " << i << endl;
        }
    }
}
// Optimal Solution
// Time Complixity -> O(n) & Space Complixity -> O(1)
vector<int> findmsrp(int arr[], int n)
{
    long long Sn = (1LL * n * (n + 1)) / 2;
    long long Sn2 = (1LL * n * (n + 1) * (2 * n + 1)) / 6;
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++)
    {
        S += arr[i];
        S2 += (long long)arr[i] * (long long)arr[i];
    }
    long long val1 = S - Sn;        // x - y
    long long val2 = S2 - Sn2;      // x^2 - y^2

    val2 = val2 / val1;             // x + y

    long long x = (val1 + val2) / 2;  // repeating
    long long y = x - val1;           // missing

    return {(int)x, (int)y};
}
int main()
{
    int arr[] = {4, 3, 6, 2, 1, 1};
    int n = 6;
    // missing(arr, n);
    vector<int> arr1 = findmsrp(arr, n);
    for (int i = 0; i < arr1.size(); i++)
    {
        cout << arr1[i] << ", " << endl;
    }

    return 0;
}