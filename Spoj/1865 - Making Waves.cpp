#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;
#define PI 3.14159265

vector<double> fx;
int n;

pair<int, int> verificar()
{
    int i, j;
    double input;
    bool ok = true;

    for(i = 400; i <= 600; i++)
    {
        for(j = 400; j <= i; j++)
        {
            ok = true;
            for(int k = 1;k <= n; k++)
            {
                input = sin((double)(i*k*PI)/(n*180)) + sin((double)(j*k*PI)/(n*180));
                //cout << input << " K: " << k << " fabs: " << fabs(fx[k-1] - input) << endl;
                if(fabs(fx[k-1] - input) >= 1e-5){
                    ok = false;
                    break;
                }
            }
            if (ok) return make_pair(i, j);
        }
    }
    return make_pair(-1, -1);
}

int main()
{
    double input;
    int cont = 0, i;
    pair<int, int> result;

    while(true)
    {
        scanf("%d", &n);
        if(n == 0) break;

        for(i = 0; i < n; i++)
        {
            scanf("%lf", &input);
            fx.push_back(input);
        }
        result = verificar();
        if(result.first > result.second)
            cout << "Case " << ++cont << ", f1 = " << result.second << ", f2 = " << result.first << "\n";
        else
            cout << "Case " << ++cont << ", f1 = " << result.first << ", f2 = " << result.second << "\n";
        fx.clear();
    }
    return 0;
}
