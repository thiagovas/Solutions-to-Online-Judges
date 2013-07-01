#include <cstdio>
#include <iostream>
using namespace std;

int k;
bool isLucky(int i)
{
    int cont = 0;
    while(i > 0)
    {
        if(i%10 == 4 || i%10 == 7) cont++;
        i /= 10;
        if(cont > k) return false;
    }
    return true;
}

int main()
{
    int n, cont = 0, temp;
    scanf("%d %d", &n, &k);
    
    while(n-- > 0)
    {
        scanf("%d", &temp);
        if(isLucky(temp)) cont++;
    }
    printf("%d\n", cont);
    return 0;
}
