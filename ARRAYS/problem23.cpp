#include <iostream>
using namespace std;
// Rearrange The Element By Thier Sign
// Brute Force
// Time Complexity - O(2n) & Space Complexity -> O(n)
void arrange(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
    int posi[n / 2];
    int neg[n / 2];
    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            neg[a++] = arr[i];
        }
        else
        {
            posi[b++] = arr[i];
        }
    }

    for (int i = 0; i < n / 2; i++)
    {
        arr[2 * i] = posi[i];
        arr[2 * i + 1] = neg[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
}
// Optimal
// Time Complexity - O(n) & Space Complexity -> O(n)
void arrange2(int arr[], int n)
{
    int arr2[n];
    int pos = 0;
    int neg = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            arr2[pos] = arr[i];
            pos = pos + 2;
        }
        else
        {
            arr2[neg] = arr[i];
            neg = neg + 2;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr2[i] << ", ";
    }
}
int main()
{
    int arr[10] = {1, 2, -2, 2, -3, 4, 5, -4, -1, -3};
    // arrange(arr, 10);
    arrange2(arr, 10);
    return 0;
}