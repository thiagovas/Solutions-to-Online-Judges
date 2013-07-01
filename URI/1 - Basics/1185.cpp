#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    float soma = 0, temp;
    int j;
    char op;
    
    scanf("%c", &op);
    for(int i = 0; i < 12; i++)
    {
        for(j = 0; j < 11-i; j++)
        {
            scanf("%f", &temp);
            soma += temp;
        }
        
        for(j = 11-i; j < 12; j++)
            scanf("%f", &temp);
    }
    
    if(op == 'S')
        printf("%.1f\n", soma/66);
    else
        printf("%.1f\n", soma/66);
    
    return 0;
}
