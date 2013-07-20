#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

int reverte(int n)
{
    int retorno = 0;
    while(n != 0)
    {
        retorno *= 10;
        retorno += n%10;
        n/=10;
    }
    return retorno;
}

int main()
{
    int n, a, b;
    cin >> n;
    
    while(n-- > 0)
    {
        cin >> a >> b;
        printf("%d\n", reverte(reverte(a)+reverte(b)));
    }
    return 0;
}

