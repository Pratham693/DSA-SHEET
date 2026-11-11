#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Longest Consecutive Sequence
// Better Version
// Time Complexity -> O(nlogn) & Space Complexity -> O(1);
int Long_consec(vector<int> &a)
{
    if (a.size() == 0)
    {
        return 0;
    }
    sort(a.begin(), a.end());
    int n = a.size();
    int lastsmaller = 0;
    int cnt = 0;
    int longest = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] - 1 == lastsmaller)
        {
            cnt += 1;
            lastsmaller = a[i];
        }
        else if (lastsmaller != a[i])
        {
            cnt = 1;
            lastsmaller = a[i];
        }
        longest = max(longest, cnt);
    }
    return longest;
}
// Optimal Version
// Time Complexity -> O(3n) And Space Complexity -> O(n)
int Long_consec2(vector<int> &a)
{
    int n = a.size();
    if (n == 0)
    {
        return 0;
    }
    int longest = 1;
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(a[i]);
    }
    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

int main()
{
    vector<int> v1 = {102, 4, 100, 1, 101, 3, 2, 1, 1};
    cout << Long_consec(v1);
    cout << endl;
    cout << Long_consec2(v1);
    return 0;
}