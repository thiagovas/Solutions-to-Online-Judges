#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    float a, b, c;
    scanf("%f%f%f", &a, &b, &c);
    
    if(a == 0)
    {
        printf("Impossivel calcular\n");
    }
    else
    {
        printf("R1 = %.5f\n", (b*(-1) + sqrt(b*b - 4*a*c))/(2*a));
        printf("R2 = %.5f\n", (b*(-1) - sqrt(b*b - 4*a*c))/(2*a));
    
    }
    return 0;
}
