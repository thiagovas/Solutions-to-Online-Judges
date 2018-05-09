#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fll
#define BUFF ios::sync_with_stdio(false);
typedef long long int ll;
typedef long double ld;

#define MAXN 200001

int seg[4*MAXN];
int v[MAXN];

void build(int node, int l, int r) {
  if(l == r) seg[node] = v[l];
  else {
    int mid = (l+r)/2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    seg[node] = seg[2*node] + seg[2*node+1];
  }
}

int rsq(int node, int l, int r, int i, int j) {
  if(l > j or r < i) return 0;
  if(i <= l and r <= j) return seg[node];
  
  int mid = (l+r)/2;
  int p1 = rsq(2*node, l, mid, i, j);
  int p2 = rsq(2*node+1, mid+1, r, i, j);
  return p1+p2;
}

void upd(int node, int l, int r, int pos, int value) {
  if(pos < l or pos > r) return;
  if(l == r) {
    seg[node] = value;
    return;
  }
  
  int mid = (l+r)/2;
  upd(2*node, l, mid, pos, value);
  upd(2*node+1, mid+1, r, pos, value);
  seg[node] = seg[2*node] + seg[2*node+1];
}


int main() {
  BUFF;

  int teste = 1;

  while(true) {
    int t, x, y;  string cmd;
    
    cin >> t;
    if(not cin) break;
    if(t == 0) break;
    if(teste > 1) cout << endl;
    
    memset(seg, 0, sizeof(seg));
    memset(v, 0, sizeof(v));
    cout << "Case " << teste++ << ":\n";
    for(int i = 0; i < t; i++)
      cin >> v[i];

    build(1, 0, t-1);

    while(true) {
      cin >> cmd;
      if(cmd == "END") break;
      
      cin >> x >> y;
      if(cmd == "M") {
        cout << rsq(1, 0, t-1, x-1, y-1) << endl;
      }
      else if(cmd == "S") {
        upd(1, 0, t-1, x-1, y);
      }
    }
  }
  
  return 0;
}
