#include <iostream>
#include<vector>
using namespace std;

// better version;
void onesapper(int arr[], int n)
{
    int hasmap[n+1] = {0};
    for (int i = 0; i < n; i++)
    {
        hasmap[arr[i]] += 1;
    }
    for (int i = 0; i < n+1; i++)
    {
        if (hasmap[i] == 1)
        {
            cout << i<<endl;
        }
        
        
    }
}
// Optimized Version 
int ones_1(int arr[], int N){
    int xor2 = 0;
    
    for (int i = 0; i < N; i++)
    {
        xor2 ^= arr[i];
        
        
    }
    
    return xor2;
    

}

int main()
{
    int arr[5] = {1, 1, 2, 2, 3};
    // onesapper(arr, 10);
    cout<<ones_1(arr, 5);
    return 0;
}