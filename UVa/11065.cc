/*
 * Solution for 11065 - A Gentlemen's Agreement
 * URL: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2006 
 */

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define MAXN 65
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fll
typedef long long int ll;
typedef long double ld;

ll graph[MAXN], n;
ll cnt, maximum;

void dp(ll u, ll forbidden, ll sz)
{
  for(ll i = u+1; i < n; i++)
    if((forbidden&(1ll<<i))==0)
      dp(i, (forbidden|graph[i]), sz+1);
  
  if(__builtin_popcountll(forbidden) == n) cnt++;
  maximum = max(maximum, sz);
}

int main()
{
  ios::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
  
  ll t, m, u, v;

  cin >> t;
  while(t--)
  {
    cin >> n >> m;
    memset(graph, 0, sizeof(graph));
    cnt=0, maximum=0, oia=0;
    for(int i = 0; i < n; i++)
      graph[i] |= (1ll<<i);
    while(m--)
    {
      cin >> u >> v;
      graph[u] |= (1ll<<v);
      graph[v] |= (1ll<<u);
    }
    
    for(int i = 0; i < n; i++)
      dp(i, graph[i], 1);
    
    cout << cnt << endl << maximum << endl;
  }

  return 0;
}
