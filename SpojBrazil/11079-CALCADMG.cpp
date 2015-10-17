#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <locale>
#include <utility>
#include <queue>
#include <stack>
using namespace std;

#define endl "\n"
typedef long long int ll;

int gcd(int a, int b)
{
    int temp=0;
    while(b != 0)
    {
        temp=a;
        a=b;
        b=temp%b;
    }
    return a;
}

int main()
{
    ios::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
    int t, a, b, c, d;

    cin >> t;
    while(t--)
    {
        cin >> a >> b >> c >> d;
        cout << gcd(abs(c-a), abs(d-b))+1 << endl;        
    }
    return 0;
}
