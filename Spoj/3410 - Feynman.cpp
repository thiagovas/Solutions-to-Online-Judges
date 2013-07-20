#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n, cont;
    while(true)
    {
        scanf("%d", &n);
        if(n == 0) break;
        cont = 1;
        while(n > 1)
        {
            cont += n*n;
            n--;
        }
        cout << cont << endl;
    }
    return 0;
}


