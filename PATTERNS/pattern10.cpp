#include <iostream>
using namespace std;
void Pattern(int n)
{
    int start = 1;
    for (int i = 0; i < n; i++)
    {

        if (i % 2 == 0)
        {
            start = 1;
        }
        else
        {
            start = 0;
        }
        for (int j = 0; j <= i; j++)
        {
            cout << start;
            //Flip THE START TO ZERO(0) OR ONE(1)
            start = 1-start;
        }
        cout << endl;
    }
}

int main()
{
    Pattern(5);

    return 0;
}