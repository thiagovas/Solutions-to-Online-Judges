// Code for the Stamp Rally problem
// Link: https://agc002.contest.atcoder.jp/tasks/agc002_d

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define mp make_pair
#define pb push_back
#define BUFF ios::sync_with_stdio(false);
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> ii;

#define MAXN 100001

typedef struct sQuery {
  int x, y, z;
  sQuery() {}
  sQuery(int px, int py, int pz) : x(px), y(py), z(pz) {}
} query;

int n;
int uf[MAXN];
int vsz[MAXN], ranko[MAXN];
vector<query> vq;
int vleft[MAXN], vright[MAXN];
vector<ii> vedges;


void initUnionFind(int psz) {
  memset(ranko, 0, sizeof(ranko));
  for(int i = 0; i <= psz; i++) {
    uf[i] = i;
    vsz[i] = 1;
  }
}

int Find(int a) {
  return (uf[a] == a) ? a : (uf[a] = Find(uf[a]));
}

void Union(int a, int b) {
  a = Find(a), b = Find(b);
  if(a != b) {
    if(ranko[a] > ranko[b]) swap(a, b);
    vsz[b] += vsz[a];
    uf[a] = b;
    if(ranko[a] == ranko[b]) ranko[b]++;
  }
}

int main() {
  BUFF; cin.tie(0);  cout.tie(0);

  int m, a, b, q;
  cin >> n >> m;

  for(int i = 0; i < m; i++) {
    cin >> a >> b;
    vedges.pb(mp(a-1, b-1));
  }

  cin >> q;
  for(int i = 0; i < q; i++) {
    query neue;
    cin >> neue.x >> neue.y >> neue.z;
    neue.x--;  neue.y--;
    vq.pb(neue);
  }

  // Initializing the lefts and rights...
  for(int i = 0; i < q; i++) {
    vleft[i] = 0;
    vright[i] = m-1;
  }

  int walko = 31;
  while(walko--) {
    vector<vector<int> > hashzao(m);
    initUnionFind(n+1);

    for(int i = 0; i < q; i++) {
      if(vleft[i] < vright[i]) {
        int mid = (vleft[i]+vright[i])/2;
        hashzao[mid].pb(i);
      }
    }

    for(int i = 0; i < m; i++) {
      Union(vedges[i].first, vedges[i].second);

      for(int j = 0; j < hashzao[i].size(); j++) {
        int idx = hashzao[i][j];
        int reached = 0;

        if(Find(vq[idx].x) == Find(vq[idx].y)) reached = vsz[Find(vq[idx].x)];
        else reached = vsz[Find(vq[idx].x)] + vsz[Find(vq[idx].y)];

        if(reached >= vq[idx].z) vright[idx] = i;
        else vleft[idx] = i+1;
      }
    }
  }

  for(int i = 0; i < q; i++)
    cout << vright[i]+1 << endl;

  return 0;
}
