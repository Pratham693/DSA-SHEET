#include <iostream>
using namespace std;

bool isPossible(int arr[], int n, int painters, int maxTime)
{
    int painterCount = 1;
    int time = 0;

    for (int i = 0; i < n; i++)
    {
        if (time + arr[i] <= maxTime)
        {
            time += arr[i];
        }
        else
        {
            painterCount++;
            time = arr[i];

            if (painterCount > painters)
                return false;
        }
    }

    return true;
}

int painterPartition(int arr[], int n, int painters)
{
    int low = 0;
    int high = 0;

    for (int i = 0; i < n; i++)
    {
        low = max(low, arr[i]);
        high += arr[i];
    }

    int ans = high;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, n, painters, mid))
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
    int arr[] = {10, 20, 30, 40};
    int n = 4;
    int painters = 2;

    cout << painterPartition(arr, n, painters);

    return 0;
}