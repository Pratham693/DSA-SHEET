#include <iostream>
using namespace std;
// Sort a Array which Have Element (0, 1, 2);
// Brute Force - Using Sorting Algorithm
// Time Complexity = O(nlogn) And Space Time O(n)
void merge(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int L[n1];
    int R[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[low + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0, key = low;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[key++] = L[i++];
        }
        else if (L[i] > R[j])
        {
            arr[key++] = R[j++];
        }
    }
    while (i < n1)
    {
        arr[key++] = L[i++];
    }
    while (j < n2)
    {
        arr[key++] = R[j++];
    }
}
void merge_sort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int mid = low + (high - low) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
// Better Approach
// Time Complexity = O(2n) But Space Complexity = O(1)
void sort1(int arr[], int n)
{
    int count = 0, count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            count++;
        }
        else if (arr[i] == 1)
        {
            count1++;
        }
        else
        {
            if (arr[i] == 2)
            {
                count2++;
            }
        }
    }
    for (int i = 0; i < count; i++)
    {
        arr[i] = 0;
    }
    int a = count + count1;
    for (int i = count; i < a; i++)
    {
        arr[i] = 1;
    }
    int b = a + count2;
    for (int i = a; i < b; i++)
    {
        arr[i] = 2;
    }
}
// Optimal Solution
// Time Complexity = O(n) and Space Complexiity = O(1);
void Sort_using_3Pointer(int arr[], int n)
{
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while (mid < high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            mid++;
            low++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    int arr[10] = {1, 2, 1, 0, 1, 2, 0, 1, 0, 1};
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
    // merge_sort(arr, 0, 9);
    // sort1(arr, 10);
    Sort_using_3Pointer(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << ", ";
    }

    return 0;
}