#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
// Next Pernmutation Problem
// Time Complexity = O(3n) And Space Complexity -> O(1);
void next_permutation(vector<int> &A)
{
    int index = -1;
    int n = A.size();
    for (int i = n - 2; i >= 0; i--)
    {
        if (A[i] < A[i + 1])
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        reverse(A.begin(), A.end());
        for (int i = 0; i < n; i++)
        {
            cout << A[i] << ", ";
        }
    }
    for (int i = n - 1; i > index; i--)
    {
        if (A[i] > A[index])
        {
            swap(A[i], A[index]);
            break;
        }
    }
    
        reverse(A.begin() + index + 1, A.end());
        for (int i = 0; i < n; i++)
        {
            cout << A[i] << ", ";
        }

}
int main()
{
    vector<int> A = {1, 2, 3, 4, 5};
    next_permutation(A);
    return 0;
}