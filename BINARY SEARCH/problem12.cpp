#include <iostream>
#include <cmath>
using namespace std;
// Koko Eating Banana Problem
// Time Complixity -> O(N) X O(log N)
// For Finding The Maximum Value Form The Array
int maxnumber(int arr[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (ans <= arr[i])
        {
            ans = arr[i];
        }
    }
    return ans;
}
// Calculating The Tota Hours
int calculateHour(int arr[], int a, int n)
{
    int totaltime = 0;

    for (int i = 0; i < n; i++)
    {
        totaltime += (arr[i] + a - 1) / a;
    }

    return totaltime;
}
int minimumRateToEatTheBanana(int arr[], int n, int h)
{
    int high = maxnumber(arr, n);
    int low = 1;
    int ans = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int total_hours = calculateHour(arr, mid, n);
        if (total_hours <= h)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int main()
{
    int arr[] = {3, 4, 6, 8, 11};
    cout << maxnumber(arr, 5);
    cout << endl;
    cout << minimumRateToEatTheBanana(arr, 5, 10);
    return 0;
}