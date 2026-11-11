#include <iostream>
#include <vector>
using namespace std;
// Row With Maximum Number of 1s
int binary_search_lower_bound(vector<int> &arr, int n, int target)
{
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (ans == n)
    {
        cout << "Hypothetical index " << n << endl;
        return n;
    }
    else
    {
        return ans;
    }
}
int rowWithMaximum(vector<vector<int>> &matrix, int n, int m)
{
    int cnt_max = 0;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        int cnt_ones = m - binary_search_lower_bound(matrix[i], m, 1);
        // cout << cnt_ones << endl;
        if (cnt_ones > cnt_max)
        {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}
int main()
{
    vector<vector<int>> arr = {
        {0, 0, 1, 1, 1},
        {0, 1, 1, 1, 1},
        {0, 0, 0, 1, 1}

    };
    cout << rowWithMaximum(arr, 3, 5);

    return 0;
}