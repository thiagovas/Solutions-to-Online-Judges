#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
    int n, temp, i, metade;
    bool ehprimo = false;
    
    scanf("%d", &n);
    while(n-- > 0)
    {
        scanf("%d", &temp);
        
        metade = temp>>1;
        ehprimo = true;
        if(temp%2 == 0)
        {
            ehprimo = false;
        }
        else
        {
            for(i = 3; i <= metade && i < 5000; i+=2)
                if(temp%i == 0)
                {
                    ehprimo = false;
                    break;
                }
        }
        
        if(ehprimo)
            printf("%d eh primo\n", temp);
        else
            printf("%d nao eh primo\n", temp);
    }
    
    return 0;
}
