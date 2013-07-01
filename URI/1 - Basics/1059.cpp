#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    register int i = 0;
    for(i = 2; i <= 100; i++)
        if(i%2 == 0) printf("%d\n", i);
    return 0;
}
