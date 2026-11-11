#include <iostream>
#include <vector>
#include <map>
using namespace std;
// Problem -> Majority Element > n/3;
// Brute Force
// Time Complexity = O(n^2) & Space Complexity O(1)

vector<int> majority(vector<int> &nums)
{
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        bool alreadypresent = false;
        for (int x : ans)
        {
            if (x == nums[i])
            {
                alreadypresent = true;
                break;
            }
        }

        if (alreadypresent)
        {
            continue;
        }
        int count = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[i] == nums[j])
            {
                count++;
            }
        }
        if (count > nums.size() / 3)
        {
            ans.push_back(nums[i]);
        }
    }
    return ans;
}
// Using HashMap _ Better approch
// Time Complexity -> O(n) & Space Complexity -> O(n);
vector<int> majority2(vector<int> v1)
{
    vector<int> ans;
    map<int, int> mpp;
    int n = v1.size();
    int mini = (int)(n / 3) + 1;
    for (int i = 0; i < n; i++)
    {
        mpp[v1[i]] += 1;
        if (mpp[v1[i]] == mini)
        {
            ans.push_back(v1[i]);
        }
        if (ans.size() == 2)
        {
            break;
        }
    }
    return ans;
}
// Optimal Solution
vector<int> majority3(vector<int> v1)
{
    int count1 = 0, count2 = 0;
    int el1 = 0;
    int el2 = 0;
    for (int i = 0; i < v1.size(); i++)
    {
        if (count1 == 0 && v1[i] != el2)
        {
            count1 = 1;
            el1 = v1[i];
        }
        else if (count2 == 0 && v1[i] != el1)
        {
            count2 = 1;
            el2 = v1[i];
        }
        else if (v1[i] == el1)
        {
            count1++;
        }
        else if (v1[i] == el2)
        {
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    vector<int> ans;
    count1 = 0, count2 = 0;
    for (int i = 0; i < v1.size(); i++)
    {
        if (v1[i] == el1)
        {
            count1++;
        }
        else if (v1[i] == el2)
        {
            count2++;
        }
    }

    int mini = v1.size() / 3;   
if (count1 > mini) ans.push_back(el1);
if (count2 > mini) ans.push_back(el2);
    return ans;
}
int main()
{
    vector<int> nums = {1, 1, 1, 2, 3, 3, 3};
    vector<int> ans = majority3(nums);
    for (int x : ans)
    {
        cout << x << ", ";
    }

    return 0;
}