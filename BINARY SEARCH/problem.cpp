#include <iostream>
using namespace std;
// Lower Bound
// Time Complixity -> O(log N)
int binary_search_lower_bound(int arr[], int n, int target)
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
// UpperBound
int upper_bound(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > target)
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
int main()
{

    int arr[10] = {12, 14, 19, 24, 34, 39, 45, 49, 50, 67};
    cout << binary_search_lower_bound(arr, 10, 12);
    cout<<endl;
    cout << upper_bound(arr, 10, 19);
    return 0;
}