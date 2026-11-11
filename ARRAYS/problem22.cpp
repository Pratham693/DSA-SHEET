#include <iostream>
using namespace std;
// Majority Elemenet
// Brute Force
// Time Complexity - O(n2)
int majority1(int arr[], int n)
{
    int count;
    for (int i = 0; i < n; i++)
    {
        count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == arr[i])
            {
                count++;
            }
        }

        if (count > n / 2)
        {
            return arr[i];
        }
    }
    return -1;
}
// Better Force
// Time Complexity - O(nlogn)
void majority(int arr[], int n)
{
    int hasmap[4] = {0};
    for (int i = 0; i < n; i++)
    {
        hasmap[arr[i]] += 1;
    }
    for (int i = 0; i < 3; i++)
    {
        if (hasmap[i] > n / 2)
        {
            cout << i;
        }
    }
}
// Optimal Force
// Time Complexity - O(n);
// Space Complexity - O(1);
int moosealgorithm(int arr[], int n)
{
    int count = 0;
    int el;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            count = 1;
            el = arr[i];
        }
        else if (arr[i] == el)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    int count1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == el)
        {
            count1++;
        }
    }
    if (count1 > n / 2)
    {
        return el;
    }

    return -1;
}

int main()
{
    int arr[10] = {1, 2, 2, 3, 3, 2, 2, 2, 2, 3};
    majority(arr, 10);
    cout << endl;
    cout << majority1(arr, 10);
    cout << endl;
    cout << moosealgorithm(arr, 10);
    
    return 0;
}