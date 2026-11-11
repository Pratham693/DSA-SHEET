#include <iostream>
#include <string>

void print_name(int i, int n)
{
    if (i > n)
    {
        return;
    }
    printf("Pratham\n");
    i++;
    print_name(i, n);
}
using namespace std;

int main()
{
    print_name(1, 10);
    return 0;
}