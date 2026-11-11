#include <iostream>
#include <vector>
using namespace std;
// Search In 2D Matrix Part II
void printmatrix(int arr[][5], int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
vector<int> SearchMatrix(int arr[][5], int n, int m, int target)
{
    int row = 0;
    int col = m - 1;
    while (row < n && col >= 0)
    {
        if (arr[row][col] == target)
        {
            vector<int> temp;
            temp = {row, col};
            cout << "Founded In The Matrix at Cordinate" << endl;
            return temp;
        }
        else if (arr[row][col] < target)
        {
            row++;
        }
        else
        {
            col--;
        }
    }

    return {-1, -1};
}

int main()
{
    int arr[5][5] = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};

    // printmatrix(arr, 5);
    vector<int> temp = SearchMatrix(arr, 5, 5, 8);
    cout << temp[0] << ", " << temp[1] << endl;
    return 0;
}