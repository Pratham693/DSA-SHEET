#include <iostream>
#include <set>
#include <bits/stdc++.h>
using namespace std;
void unioun(int arr[], int arr2[], int n1, int n2)
{
    set<int> s;
    for (int i = 0; i < n1; i++)
    {
        s.insert(arr[i]);
    }
    for (int i = 0; i < n2; i++)
    {
        s.insert(arr2[i]);
    }
    int n = s.size();
    int temp[n];
    int i = 0;
    for (auto it: s)
    {
        temp[i] = it;
        cout<<temp[i]<<", ";
        i++;
        it++;
        
    }
    
  
    
    
}
int main()
{
    int arr[10] = {1, 2, 3, 4, 4, 5, 6, 6, 7, 8};
    int arr2[5] = {1, 3, 5, 6, 7};
 unioun(arr, arr2, 10, 5);
    return 0;
}