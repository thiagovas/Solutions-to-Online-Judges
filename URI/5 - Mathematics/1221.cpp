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
    int n, i, j;
    int temp;
    
    cin >> n;
    while(n-- > 0)
    {
        cin >> temp;
        if(temp == 2)
        {
            printf("Prime\n");
        }
        else if(temp % 2 == 0)
        {
            printf("Not Prime\n");
        }
        else
        {
            j = min(50000, temp);
            for(i = 3; i < j; i+=2)
                if(temp%i == 0)
                {
                    printf("Not Prime\n");
                    goto finishhim;
                }
            printf("Prime\n");
        }
        finishhim:;
    }
    return 0;
}
