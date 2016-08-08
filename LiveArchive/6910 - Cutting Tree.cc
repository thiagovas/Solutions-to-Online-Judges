#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long int ll;

class UnionFind {
  private: vector<int> p;
  public:
  void init(int n) { this->p.assign(n+1, 0); for(int i=0;i<=n;i++) p[i]=i; }
  int Find(int a) { return p[a]==a?a:Find(p[a]); }
  void Union(int a, int b) { p[Find(a)]=Find(b); }
};

int main()
{
  ios::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
  
  char type;
  int t, n, k, a, b, teste=1;
  UnionFind uf;
  vector<int> parent;
  vector<bool> taken;
  vector<pair<int, int> > queries;
  set<int> jafoi;
  
  cin >> t;
  while(t--)
  {
    cin >> n >> k;
    uf.init(n);
    queries.clear();
    jafoi.clear();
    parent.clear(); taken.clear();
    taken.resize(n, false);
    
    for(int i = 0; i < n; i++)
    {
      cin >> a;
      a--;
      parent.push_back(a);
    }
    
    while(k--)
    {
      cin >> type;
      if(type=='Q')
      {
        cin >> a >> b; a--; b--;
        queries.push_back(make_pair(a, b));
      }
      else
      {
        cin >> a; a--;
        taken[a]=true;
        if(jafoi.find(a) == jafoi.end())
        {
          queries.push_back(make_pair(a, -1));
          jafoi.insert(a);
        }
      }
    }
    
    for(int i = 0; i < n; i++)
      if(not taken[i] && parent[i] != -1) uf.Union(i, parent[i]);
    
    stack<bool> resp;
    for(int i = queries.size()-1; i >= 0; i--)
    {
      if(queries[i].second==-1) 
      {
        if(parent[queries[i].first] != -1)
          uf.Union(queries[i].first, parent[queries[i].first]);
      }
      else resp.push(uf.Find(queries[i].first) == uf.Find(queries[i].second));
    }
    
    cout << "Case #" << teste++ << ":\n";
    while(!resp.empty())
    {
      if(resp.top()) cout << "YES\n";
      else cout << "NO\n";
      resp.pop();
    }
  }
  
  
  return 0;
}
