#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <functional>
#include <utility>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    int n;
    int a, b;
    
    cin >> n;
    while(n-- > 0)
    {
        cin >> a >> b;
        if(a >= b)
        {
            while(b != 0)
            {
                if(b%10 != a%10)
                {
                    printf("nao encaixa\n");
                    goto finishhim;
                }
                
                a/=10;
                b/=10;
            }
            printf("encaixa\n");
        }
        else
        {
            printf("nao encaixa\n");
        }
        finishhim:;
    }
    return 0;
}
