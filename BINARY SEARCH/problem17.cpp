#include <iostream>
using namespace std;
// Agressive Cows
// Time Complixity O(logN) X O(n);
// Space Complixity O(1);
bool CowPlacebale(int arr[], int n, int mid, int cows)
{
    int countCows = 1;
    int last = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - last >= mid)
        {
            countCows++;
            last = arr[i];
        }
    }
    if (countCows >= cows)
    {
        return true;
    }
    return false;
}
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
int max_min_distance_between_cows(int arr[], int n, int cows)
{
    int low = 1;
    int high = maxElement(arr, n);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (CowPlacebale(arr, n, mid, cows) == true)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}
int main()
{
    int cows = 4;
    int arr[6] = {0, 3, 4, 7, 9, 10};
    cout << max_min_distance_between_cows(arr, 6, cows);
    return 0;
}