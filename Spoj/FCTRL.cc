#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF 0x3f3f3f3f
typedef long long int ll;

ll power5[30];

int main()
{
  ll p = 1, lim=0;
  while(p < INF)
  {
    power5[lim++] = p;
    p *= 5;
  }
  
  ll t, n;
  cin >> t;
  while(t--)
  {
    cin >> n;
    ll resp=0;
    for(int i = 1; i < lim; i++)
      resp += n/power5[i];
    cout << resp << endl;
  }
  
  return 0;
}
