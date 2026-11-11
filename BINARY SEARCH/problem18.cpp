#include <iostream>
using namespace std;

// Book Allocation Problem

int maxElement(int arr[], int n)
{
    int max = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= max)
        {
            max = arr[i];
        }
    }

    return max;
}

int sumElement(int arr[], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    return sum;
}

int CountStudent(int arr[], int n, int pages)
{
    int student = 1;
    int pagesStudent = 0;

    for (int i = 0; i < n; i++)
    {
        if (pagesStudent + arr[i] <= pages)
        {
            pagesStudent += arr[i];
        }
        else
        {
            student++;
            pagesStudent = arr[i];
        }
    }

    return student;
}

int Bookallocation(int arr[], int n, int std)
{
    int low = maxElement(arr, n);
    int high = sumElement(arr, n);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int students = CountStudent(arr, n, mid);

        if (students > std)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return low;
}

int main()
{
    int arr[] = {25, 46, 28, 49, 24};

    cout << Bookallocation(arr, 5, 4);

    return 0;
}