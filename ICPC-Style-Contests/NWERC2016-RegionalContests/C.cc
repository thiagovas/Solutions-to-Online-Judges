#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
typedef long long int ll;
typedef long double ld;

vector<pair<ll, ld> > vtimes;

ld fly(ld v)
{
  ld resp=0;
  for(pair<ll, ld> p : vtimes)
    resp += v*p.first*p.second;
  return resp;
}

ld bb(ld rx)
{
  ld v1=-INF, v2=INF;
  int c=100000;
  while(c--)
  {
    ld mid = (v1+v2)/2;
    ld x = fly(mid);
    if(x > rx) v2 = mid;
    else v1 = mid;
  }
  return v1;
}

int main()
{
  ios::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
  ll x, y, n, l, u, last=0;
  ld f;
  
  cin >> x >> y;
  cin >> n;
  while(n--)
  {
    cin >> l >> u >> f;
    vtimes.pb(mp(l-last, 1));
    vtimes.pb(mp(u-l, f));
    last=u;
  }
  vtimes.pb(mp(y-last, 1));
  
  cout << std::fixed << std::setprecision(10) << bb(x) << endl;
  
  return 0;
}
