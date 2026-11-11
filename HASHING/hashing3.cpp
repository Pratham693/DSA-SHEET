#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    // Pre Computing
    map<char, int> mpp;
    for (int i = 0; i < s.size(); i++)
    {
        mpp[s[i]]++;
    }
    // Fetching
    int q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        cout << mpp[c] << endl;
    }

    return 0;
}
// Time Complexity For Normal Map = O(Logn); For Fetching From Map --> For All Cases
// Time Complexity For Unordered Map = O(1); --> Best Case
// Time Complexity For Unordered Map = O(n); --> Worst Case