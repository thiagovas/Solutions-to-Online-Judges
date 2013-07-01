#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int number;
    float hours, salary;
    
    scanf("%d", &number);
    scanf("%f", &hours);
    scanf("%f", &salary);
    
    printf("NUMBER = %d\n", number);
    printf("SALARY = U$ %.2f\n", hours*salary);
    
    return 0;
}
