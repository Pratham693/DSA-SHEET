#include <iostream>
using namespace std;

// Find Minimum days To Make M Bouquets

int minElement(int arr[], int n)
{
    int min = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    return min;
}

int maxElement(int arr[], int n)
{
    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

bool possible(int arr[], int day, int Bouquet, int flower, int n)
{
    int count = 0;
    int bouquets = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= day)
        {
            count++;

            if (count == flower)
            {
                bouquets++;
                count = 0;
            }
        }
        else
        {
            count = 0;
        }
    }

    return bouquets >= Bouquet;
}

int roseGarden(int arr[], int Bouquet, int flower, int n)
{
    if ((long long)Bouquet * flower > n)
    {
        return -1;
    }

    int low = minElement(arr, n);
    int high = maxElement(arr, n);
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (possible(arr, mid, Bouquet, flower, n))
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
    int arr[] = {7, 7, 7, 7, 13, 11, 12, 7};

    int Bouquet = 2;
    int flower = 3;
    int n = 8;

    cout << roseGarden(arr, Bouquet, flower, n);

    return 0;
}