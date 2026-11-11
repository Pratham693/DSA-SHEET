#include <iostream>
using namespace std;
// Set Matrix
// Better Version
// Time Complexity ->O(2 x n x m);
// Space Complexity -> O(n) + O(m);
void setmatrix(int arr[3][3])
{
    int col[3];
    int row[3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == 0)
            {
                col[i] = 1;
                row[j] = 1;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (col[i] == 1 || row[j] == 1)
            {
                arr[i][j] = 0;
            }
        }
    }
    return;
}

// Optimal Version
// Time Complexity -> O()
void setmatrix2(int arr[3][3])
{
    int col0 = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == 0)
            {
                // mark the ith row
                arr[i][0] = 0;
                // mark the jth coloumn
                if (j != 0)
                {
                    arr[0][j] = 0;
                }
                else
                {
                    col0 = 0;
                }
            }
        }
    }

    for (int i = 1; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] != 0)
            {
                if (arr[i][0] == 0 || arr[0][j] == 0)
                {
                    arr[i][j] = 0;
                }
            }
        }
    }

    if (arr[0][0] == 0)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[0][j] = 0;
        }
    }

    if (col0 == 0)
    {
        for (int i = 0; i < 3; i++)
        {
            arr[i][0] = 0;
        }
    }
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
    setmatrix2(arr);
    cout << endl;
    print2darray(arr);
   
    return 0;
}