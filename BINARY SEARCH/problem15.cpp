#include <iostream>
using namespace std;
// Least Capacit To Ship Packages with in D Days;
int maxElement(int arr[], int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= max)
        {
            max = arr[i];
        }
    }
    return max;
}
int SumofArray(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}
int RequireDays(int arr[], int n, int capcity)
{
    int day = 1;
    int load = 0;
    for (int i = 0; i < n; i++)
    {
        if (load + arr[i] > capcity)
        {
            day += 1;
            load = arr[i];
        }
        else
        {
            load += arr[i];
        }
    }
    return day;
}
int leastCapcityForPackaging(int arr[], int n, int minimum_Days)
{
    int low = maxElement(arr, n);
    int high = SumofArray(arr, n);
    int ans = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (RequireDays(arr, n, mid) <= minimum_Days)
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
    int weight[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // cout << maxElement(weight, 10);
    cout << leastCapcityForPackaging(weight, 10, 5);
    return 0;
}