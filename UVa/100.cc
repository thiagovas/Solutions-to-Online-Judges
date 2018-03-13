#include <bits/stdc++.h>
using namespace std;

#define BUFF ios::sync_with_stdio(false);
typedef long long int ll;

#define MAXN 100000

short v[MAXN];

short vai(ll x)
{
  if(x == 1) return 1;
  if(x < MAXN && v[x] != -1) return v[x];
  
  short resp = 0;
  
  if(x%2) resp = vai(3*x+1)+1;
  else resp = vai(x/2)+1;
  
  if(x < MAXN) v[x] = resp;
  
  return resp;
}


int main()
{
  BUFF;
  
  for(int i = 0; i < MAXN; i++)
    v[i] = -1;
  
  ll a, b;
  while(true)
  {
    cin >> a >> b;
    if(not cin) break;
    short maxi = 0;
    ll begone = min(a, b), ende = max(a, b);
    
    for(int i = begone; i <= ende; i++)
      maxi = max(maxi, vai(i));
    
    cout << a << " " << b << " " << maxi << endl;
  }
  
  return 0;
}

