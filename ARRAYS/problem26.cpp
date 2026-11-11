#include <iostream>
#include <vector>
using namespace std;
// Brute Force Solution.
// Time Complexity -> O(n2) and Space- Compleixy -> O(n)
vector<int> find_leader(vector<int> &A)
{
    vector<int> Ans;
    bool flag;
    for (int i = 0; i < A.size(); i++)
    {
        int leader = A[i];
        flag = true;
        for (int j = i + 1; j < A.size(); j++)
        {
            if (leader < A[j])
            {
                flag = false;
                break;
            }
        }
        if (flag == true)
        {
            Ans.push_back(leader);
        }
    }
    return Ans;
}
// Optimal Solution
// Time Complexiy -> O(n) & Space Complexity -> O(n)
vector<int> find_leader2(vector<int> &A)
{
    vector<int> Ans;
    int Maxi = 0;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        if (A[i] > Maxi)
        {
            Ans.push_back(A[i]);
        }
        Maxi = max(Maxi, A[i]);
    }

    return Ans;
}
int main()
{
    vector<int> v1 = {1, 20, 30, 19, 10, 6, 7, 11, 4};
    vector<int> v2 = find_leader(v1);
    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2[i] << ", ";
    }
    vector<int> v3 = find_leader2(v1);
    cout << endl;

    for (int i = 0; i < v3.size(); i++)
    {
        cout << v3[i] << ", ";
    }

    return 0;
}