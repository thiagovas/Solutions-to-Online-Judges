#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    unsigned long long comb[21];
    int a, b;
    
    comb[0] = 1;
    for(register int i = 1; i < 21; i++)
        comb[i] = i*comb[i-1];
    
    while(scanf("%d %d", &a, &b) != EOF)
        cout << comb[a] + comb[b] << endl;
    return 0;
}
