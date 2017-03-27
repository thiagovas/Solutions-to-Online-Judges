#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF 0x3f3f3f3f
#define mp make_pair
#define pb push_back
typedef long long int ll;
typedef long double ld;

vector<int> v1, v2;

bool check(vector<int> &vec, int lim)
{
  int last=-1;
  for(int v : vec)
  {
    if(v > lim)
    {
      if(last == -1) last = v;
      else
      {
        if(v != last) return false;
        last=-1;
      }
    }
  }
  return (last==-1);
}

int bb()
{
  int b=0, e=INF;
  while(b < e)
  {
    int mid=(b+e)/2;
    if(check(v1, mid) && check(v2, mid)) e=mid;
    else b=mid+1;
  }
  return b;
}

int main()
{
  ios::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
  
  int n, a;
  
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    cin >> a;
    v1.pb(a);
  }
  
  for(int i = 0; i < n; i++)
  {
    cin >> a;
    v2.pb(a);
  }

  cout << bb() << endl;
  
  return 0;
}
