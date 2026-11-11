#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Missing Number Form 1 To N in a Array.
int missing(int arr[], int n, int N)
{
    int flag;
    int i;
    for (i = 1; i <= N; i++)
    {
        flag = 0;
        for (int j = 0; j < n - 1; j++)
        {
            
            if (arr[j] == i)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            cout << i << " missing" << endl;
        }
    }
}

// better
void missing2(int arr[], int n)
{

    int hash[n + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] += 1;
    }
    for (int i = 1; i < n; i++)
    {
        if (hash[i] == 0)
        {
            cout << i << ", ";
        }
    }
}
int main()
{
    int arr1[10] = {1, 3, 5, 6, 7, 8, 9, 10};
    // missing(arr1, 10, 10);
    missing2(arr1, 10);
    return 0;
}