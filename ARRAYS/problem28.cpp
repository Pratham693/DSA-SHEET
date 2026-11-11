#include <iostream>
using namespace std;
// Set Matrix
// Brute Force Solution
// Time Complexity -> O(n^3) & O(n)
void markrow(int i, int arr[3][3])
{
    for (int j = 0; j < 3; j++)
    {
        if (arr[i][j] != 0)
        {
            arr[i][j] = -1;
        }
    }
    return;
}
void markcoloum(int j, int arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        if (arr[i][j] != 0)
        {
            arr[i][j] = -1;
        }
    }
    return;
}

void setmatrix(int arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == 0)
            {
                markrow(i, arr);
                markcoloum(j, arr);
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == -1)
            {
                arr[i][j] = 0;
            }
        }
    }
    return;
}
void print2darray(int arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << ", ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[3][3] = {{1, 1, 1}, {1, 0, 0}, {1, 1, 1}};
    print2darray(arr);
    setmatrix(arr);
    cout << endl;
    print2darray(arr);

    return 0;
}