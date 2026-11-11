#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <set>
using namespace std;
// Problem -> 4 Sum
// Brute Force
// Time Complixty -> O(n^4 + nlog(n)) & Space Complixty -> O(n^2)
vector<vector<int>> sum4(int arr[], int n)
{
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    if ((arr[i] + arr[j] + arr[k] + arr[l]) == 0)
                    {
                        vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
// Better Version
// Time Complexity ->O(n^3  * log(n)) & Space Complexity -> O(n + log M)
vector<vector<int>> sum_four(int arr[], int n)
{
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        set<int> hashset;
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int third = -(arr[i] + arr[j] + arr[k]);
                if (hashset.find(third) != hashset.end())
                {
                    vector<int> temp = {arr[i], arr[j], arr[k], third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(arr[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
int main()
{
    int arr[] = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> ans = sum_four(arr, 6);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << ", ";
        }
        cout << endl;
    }
    return 0;
}