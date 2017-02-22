/*
 Solution for 11072 - Points
URL: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=35&category=22&page=show_problem&problem=2013
 */

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define EPS 1e-7
#define pb push_back
#define mp make_pair
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> ii;

typedef struct sPoint {
  ll x, y;

  sPoint() {}
  sPoint(ll _x, ll _y) : x(_x), y(_y) {}
  bool operator<(sPoint other)
  {
    if(other.x == x) return y < other.y;
    return x < other.x;
  }
} point;


int n;
vector<point> vp;
vector<ii> vleft, vright;
pair<ld, ld> midp;


ll cross(point a, point b, point c) // AB X BC
{
  a.x -= b.x; a.y -= b.y;
  b.x -= c.x; b.y -= c.y;
  return a.x*b.y - a.y*b.x;
}

ll cross(pair<ld, ld> a, point b, point c) // AB X BC
{
  a.first -= b.x; a.second -= b.y;
  b.x -= c.x; b.y -= c.y;
  return (a.first*b.y - a.second*b.x);
}

bool domeioehlixo(pair<ld, ld> a, point b, point c)
{ return cross(a, b, c)+EPS >= 0; }

bool domeioehlixo(point a, point b, point c)
{ return cross(a, b, c) >= 0; }


vector<point> convexhull()
{
  vector<point> u, l;
  sort(vp.begin(), vp.end());
  for(int i = 0; i < vp.size(); i++)
  {
    u.pb(vp[i]);
    while(u.size() > 2 && domeioehlixo(u[u.size()-3], u[u.size()-2], u[u.size()-1]))
      u.erase(u.begin()+(u.size()-2));
  }

  for(int i = vp.size()-1; i >= 0; i--)
  {
    l.pb(vp[i]);
    while(l.size() > 2 && domeioehlixo(l[l.size()-3], l[l.size()-2], l[l.size()-1]))
      l.erase(l.begin()+(l.size()-2));
  }
  u.erase(u.begin()+(u.size()-1));
  l.erase(l.begin()+(l.size()-1));
  u.insert(u.end(), l.begin(), l.end());
  return u;
}

bool insidetriangle(const pair<ld, ld> &a, const point& b, const point& c, const point& p)
{
  return cross(a, b, c)-EPS <= cross(a, b, p) + cross(a, c, p) + cross(b, c, p);
}

bool insidepolygon(const vector<point>& ch, const vector<ii>& v, point &p)
{
  int i = 0, j = v.size()-1;
  while(i <= j)
  {
    int mid=(i+j)/2;
    bool lixo1 = domeioehlixo(midp, ch[v[i].first], p);
    bool lixo2 = domeioehlixo(midp, ch[v[i].second], p);
    
    cout << "<" << ch[v[i].first].x << " " << ch[v[i].first].y << ">, ";
    cout << "<" << ch[v[i].second].x << " " << ch[v[i].second].y << "> ->";
    cout << p.x << " " << p.y << " " << lixo1 << " " << lixo2 << endl;
    if(lixo1 ^ lixo2)
      return insidetriangle(midp, ch[v[i].first], ch[v[i].second], p);
    if(lixo1) j=mid-1;
    else i=mid+1;
    if(i==j) return false;
  }
  return false;
}

int main()
{
  //ios::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
  cin >> n;

  while(n--)
  {
    point p;
    cin >> p.x >> p.y;
    vp.pb(p);
  }
  
  vector<point> ch = convexhull();

  for(int i = 0; i < ch.size(); i++)
  {
    midp.first += ch[i].x;
    midp.second += ch[i].y;
  }
  midp.first /= ch.size();
  midp.second /= ch.size();

  for(int i = 0; i < ch.size(); i++)
  {
    int j = (i+1)%ch.size();
    if(ch[i].x <= midp.first || ch[j].x <= midp.first)
      vleft.pb(mp(i, j));
    if(ch[i].x >= midp.first || ch[j].x >= midp.first)
      vright.pb(mp(i, j));
  }
  
  cin >> n;
  while(n--)
  {
    point p;
    bool resp=false;
    cin >> p.x >> p.y;
    ld dx = fabs(p.x-midp.first);
    ld dy = fabs(p.y-midp.second);
    if(dx < EPS && dy < EPS) cout << "inside\n";
    else
    {
      if(p.x >= midp.first)
      {
        if(insidepolygon(ch, vright, p)) resp=true;
      }
      else if(insidepolygon(ch, vleft, p)) resp=true;

      if(resp) cout << "inside\n";
      else cout << "outside\n";
    }
  }
  
  
  return 0;
}
