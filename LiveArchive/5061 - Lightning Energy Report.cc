#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define MAXN 50010
#define mp make_pair
#define pb push_back
typedef long long int ll;

int T[MAXN], P[MAXN][20], L[MAXN];
bool visited[MAXN];
vector<vector<int> > tree;
map<int, int> op, take;


void dfs(int u, int parent, int level)
{
  if(visited[u]) return;
  visited[u]=true;
  
  T[u]=parent; L[u]=level;
  for(int i = 0; i < tree[u].size(); i++)
    dfs(tree[u][i], u, level+1);
}

void processLCA()
{
  int i, j;
  
  for(i=0; i < tree.size(); i++)
    for(j=0; (1<<j) < tree.size(); j++)
      P[i][j] = -1;
  
  for(i=0; i < tree.size(); i++)
    P[i][0]=T[i];
  
  for(j=1; (1<<j) < tree.size(); j++)
    for(i=0; i < tree.size(); i++)
      if(P[i][j-1] != -1)
        P[i][j] = P[P[i][j-1]][j-1];
}

int lca(int p, int q)
{
  int log=1;
  if(L[p] < L[q]) swap(p, q);
  
  for(log=1; (1<<log) <= L[p]; log++); log--;
  
  for(int i = log; i >= 0; i--)
    if(L[p] - (1<<i) >= L[q])
      p = P[p][i];

  if(p==q) return p;

  for(int i = log; i >= 0; i--)
    if(P[p][i] != -1 && P[p][i] != P[q][i])
      p = P[p][i], q=P[q][i];
  return T[p];
}

int run(int u, vector<int> &resp)
{
  if(visited[u]) return 0;
  visited[u]=true;
  
  resp[u]=op[u];
  for(int i = 0; i < tree[u].size(); i++)
    resp[u] += run(tree[u][i], resp);
  resp[u]-=take[u];
  return resp[u]-take[u];
}

vector<int> solve(vector<pair<pair<int, int>, int> > &queries)
{
  memset(visited, false, sizeof(visited));
  dfs(0, 0, 0);
  processLCA();
  vector<int> resp(tree.size(), 0);
  
  for(vector<pair<pair<int, int>, int> >::iterator it = queries.begin(); it != queries.end(); it++)
  {
    int u = it->first.first, v=it->first.second;
    int common = lca(u, v);
    
    op[u] += it->second;
    op[v] += it->second;
    take[common] += it->second;
  }
  
  memset(visited, false, sizeof(visited));
  run(0, resp);
  return resp;
}

int main()
{
  ios::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
  int t, n, u, v, w;
  
  cin >> t;
  for(int caso=1; caso <= t; caso++)
  {
    cin >> n;
    vector<pair<pair<int, int>, int> > queries;
    tree.clear();  tree.resize(n);
    for(int i = 1; i < n; i++)
    {
      cin >> u >> v;
      tree[u].pb(v);
      tree[v].pb(u);
    }
    
    int q;
    cin >> q;
    while(q--)
    {
      cin >> u >> v >> w;
      queries.pb(mp(mp(u, v), w));
    }
    
    op.clear();  take.clear();
    vector<int> resp = solve(queries);
    cout << "Case #" << caso << ":\n";
    for(int i = 0; i < resp.size(); i++)
      cout << resp[i] << endl;
  }
  
  return 0;
}
