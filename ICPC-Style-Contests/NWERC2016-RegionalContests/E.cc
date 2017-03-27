#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main()
{
  ios::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
  
  int n, a;
  vector<ii> v;

  cin >> n;
  for(int i = 0; i < n; i++)
  {
    cin >> a;
    v.pb(mp(a, i));
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());

  int sum=0;
  for(int i = 1; i < n; i++)
    sum += v[i].first;
  if(v[0].first > sum) cout << "impossible\n";
  else
  {
    cout << v[0].second+1;
    for(int i = 1; i < n; i++)
      cout << " " << v[i].second+1;
    cout << endl;
  }
  
  return 0;
}
