#include <iostream>
using namespace std;
void Pattern1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
// Time Complexity = O(n^2)
// SPACE COMPLEXITY = O(1);

int main()
{
    Pattern1(5);

    return 0;
}