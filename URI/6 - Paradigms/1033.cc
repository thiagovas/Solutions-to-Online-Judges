#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long int ll;

ll mod;

vector<vector<ll> > mul(vector<vector<ll> > &a, vector<vector<ll> > &b)
{
  vector<vector<ll> > c(a.size(), vector<ll>(b[0].size(), 0));
  
  for(int i = 0; i < a.size(); i++)
    for(int j = 0; j < b[i].size(); j++)
    {
      for(int k = 0; k < a[0].size(); k++)
        c[i][j] += (a[i][k]*b[k][j])%mod;
      c[i][j] %= mod;
    }
  return c;
}

vector<vector<ll> > exp(vector<vector<ll> > &v, ll n)
{
  if(n==1) return v;
  
  vector<vector<ll> > r = exp(v, n/2);
  r = mul(r, r);
  if(n%2) return mul(r, v);
  else return r;
}

int main()
{
  ios::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
  ll n, teste=1;
  vector<vector<ll> > base(3);
  base[0].push_back(1); base[0].push_back(0); base[0].push_back(0);
  base[1].push_back(0); base[1].push_back(0); base[1].push_back(1);
  base[2].push_back(1); base[2].push_back(1); base[2].push_back(1);
  
  while(true)
  {
    cin >> n >> mod;
    if(not cin) break;
    if(n==0 && mod==0) break;

    if(n==0 || n==1) cout << "Case " << teste++ << ": " << n << " " << mod << " 1\n";
    else
    {
      vector<vector<ll> > r = exp(base, n);
      ll result = (r[1][0] + r[1][1] + r[2][1])%mod;
      cout << "Case " << teste++ << ": " << n << " " << mod << " " << result << endl;
    }
  }
  
  return 0;
}
