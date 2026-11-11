#include <iostream>
using namespace std;
// Search in 2d shorted Matrix  
bool searchMatrix(int matrix[][4], int rows, int cols, int target) {

    int start = 0;
    int end = rows * cols - 1;

    while (start <= end) {

        int mid = start + (end - start) / 2;

        int row = mid / cols;
        int col = mid % cols;

        if (matrix[row][col] == target) {
            return true;
        }
        else if (matrix[row][col] < target) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return false;
}

int main() {

    int matrix[3][4] = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target = 16;

    if (searchMatrix(matrix, 3, 4, target)) {
        cout << "Element Found";
    }
    else {
        cout << "Element Not Found";
    }

    return 0;
}