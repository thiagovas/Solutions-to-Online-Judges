#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long int ll;

int LSOne(int i) { return (i&(-i)); }

class BIT {
  private: vector<int> ft;
  public: void clear() {ft.clear();}
  void resize(int n) {ft.assign(n+1, 0);}
  int rsq(int b) {
    int sum=0; for(;b;b-=LSOne(b)) sum += ft[b];
    return sum;
  }
  int rsq(int a, int b)
  {
    return rsq(b) - (a==1?0:rsq(a-1));
  }
  void add(int v, int k)
  {
    for(;k<(int)ft.size(); k+=LSOne(k)) ft[k]+=v;
  }
};

BIT b[2000];

int main()
{
  ios::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
  
  int x, y, z, w, p, q, n;
  char type;
  
  while(true)
  {
    cin >> x >> y >> p;
    if(not cin) break;
    if(x==0 && y==0 && p==0) break;
    
    
    for(int i = 0; i < y; i++)
    {
      b[i].clear();
      b[i].resize(x+2);
    }
    
    cin >> q;
    while(q--)
    {
      cin >> type;
      if(type=='A')
      {
        cin >> n >> x >> y;
        b[y].add(p*n, x+1);
      }
      else
      {
        cin >> x >> y >> z >> w;
        if(x > z) swap(x, z);  if(y > w) swap(y, w);
        int resp=0;
        for(int i = y; i <= w; i++)
          resp+=b[i].rsq(x+1, z+1);
        cout << resp << endl;
      }
    }
    cout << endl;
  }
  
  return 0;
}
