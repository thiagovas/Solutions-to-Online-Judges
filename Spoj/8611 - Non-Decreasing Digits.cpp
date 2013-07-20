#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int p, dtNumber, n, cont, i;
    long long soma, temp;
    long long digSoma[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    
    scanf("%d", &p);
    while(p-- > 0)
    {
        scanf("%d %d", &dtNumber, &n);
        if(n == 1)
        { 
            printf("%d %d\n", dtNumber, 10);
            continue;
        }
        else if(n == 2)
        {
            printf("%d %d\n", dtNumber, 55);
            continue;
        }
        
        cont = 2;
        soma = 55;
        temp = 10;
        for(i = 0; i < 10; i++)
        {
            digSoma[i] = temp--;
        }
        temp = 0;
        
        while(cont++ < n)
        {
            for(i = 0; i < 10; i++)
            {
                temp = digSoma[i];
                digSoma[i] = soma;
                soma -= temp;
            }
            for(i = 0; i < 10; i++)
            {
                soma += digSoma[i];
            }
        }
        cout << dtNumber << " " << soma << endl;
    }
    return 0;
}
