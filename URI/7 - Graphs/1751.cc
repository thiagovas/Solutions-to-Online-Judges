#include <iostream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <algorithm>
#include <set>
#include <utility>
#include <vector>
#include <locale>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
using namespace std;
 
#define endl "\n"
#define MAX 150000
typedef long long int ll;
 
typedef struct sNode {
  bool amigo; ll fica, volta;
  sNode(){} sNode(ll _f, ll _v, bool _a){ fica=_f;  volta=_v; amigo=_a; }
} node;
 
node vNodes[MAX];
vector<vector<pair<int, ll> > > graph;
 
bool roda(int n)
{
    ll sum=0, miniv=0;
    bool eh = vNodes[n].amigo, tem=false;
    for(unsigned int i = 0; i < graph[n].size(); i++)
    {
      tem = roda(graph[n][i].first);
      eh=eh||tem;
      if(not tem) continue;
      ll t = (vNodes[graph[n][i].first].volta += graph[n][i].second);
      if(vNodes[graph[n][i].first].fica-t < miniv) miniv = vNodes[graph[n][i].first].fica-t;
      sum += t;
    }
    if(not eh) return false;
    vNodes[n].volta = sum;
    if(graph[n].size() > 0) vNodes[n].fica = sum+miniv;
    return true;
}
 
int main()
{
  ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
  int n, f, a, b, c;
   
  while(true)
  {
    cin >> n >> f;
    if(not cin) break;
    if(n==0 && f==0) break;
      
    graph.clear();
    for(int i = 0; i < n; i++) vNodes[i] = sNode(0, 0, false);
    graph.resize(n);
    n--;
    while(n--)
    {
      cin >> a >> b >> c;
      a--; b--;
      graph[a].push_back(make_pair(b, c));
    }
 
    while(f--)
    {
      cin >> a;
      vNodes[a-1].amigo=true;
    }
     
    vNodes[0].amigo=false;
    roda(0);
    cout << vNodes[0].fica << endl;
  }
  return 0;
}
