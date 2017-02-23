/*
 * Solution for 11072 - Points
 * URL: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=35&category=22&page=show_problem&problem=2013
 */

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define EPS 1e-7
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define mp make_pair
#define pb push_back
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> ii;

typedef struct sPoint {
  ll x, y;

  sPoint() {}
  sPoint (ll _x, ll _y) : x(_x), y(_y) {}
  bool operator<(const sPoint& other) const
  {
    if(x == other.x) return y < other.y;
    return x < other.x;
  }
} point;

vector<point> vp, ch;

ll cross(point a, point b, point c) // AB x BC
{
  a.x -= b.x;  a.y -= b.y;
  b.x -= c.x;  b.y -= c.y;
  return a.x*b.y - a.y*b.x;
}

vector<point> convexhull()
{
  sort(vp.begin(), vp.end());

  vector<point> l, u;
  for(int i = 0; i < vp.size(); i++)
  {
    while(l.size() > 1 && cross(l[l.size()-2], l[l.size()-1], vp[i]) <= 0)
      l.pop_back();
    l.pb(vp[i]);
  }

  for(int i = vp.size()-1; i >= 0; i--)
  {
    while(u.size() > 1 && cross(u[u.size()-2], u[u.size()-1], vp[i]) <= 0)
      u.pop_back();
    u.pb(vp[i]);
  }
  l.pop_back();  u.pop_back();
  l.insert(l.end(), u.begin(), u.end());
  return l;
}

ll area(point a, point b, point c)
{ return llabs(cross(a, b, c)); }

bool insideTriangle(point a, point b, point c, point p)
{
  return area(a, b, c) == (area(a, b, p) + 
                           area(a, c, p) +
                           area(b, c, p));
}

bool isInside(point p)
{
  if(ch.size() < 3) return false;

  int i = 2, j = ch.size()-1;

  while(i < j)
  {
    int mid = (i+j)/2;
    ll c = cross(ch[0], ch[mid], p);
    if(c > 0) i = mid+1;
    else j = mid;
  }
  return insideTriangle(ch[0], ch[i], ch[i-1], p);
}

int main()
{
  ios::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
  
  int n;

  while(true)
  {
    ch.clear();
    vp.clear();
    cin >> n;
    if(not cin) break;

    while(n--)
    {
      point p;
      cin >> p.x >> p.y;
      vp.pb(p);
    }

    ch = convexhull();

    cin >> n;
    while(n--)
    {
      point p;
      cin >> p.x >> p.y;
      if(isInside(p)) cout << "inside\n";
      else cout << "outside\n";
    }
  }
  
  return 0;
}
