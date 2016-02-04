#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define PII pair<int, int>
#define PLL pair<ll, ll>
typedef long long int ll;
typedef long double ld;


int main()
{
  ios::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
  set<ll> s;
  ll n, temp, a;
  
  while(true)
  {
    cin >> n;
    if(not cin) break;
    if(n==0) break;
    
    s.clear();
    for(int i = 1; i < n; i++) s.insert(i);
    
    cin >> temp; n--;
    while(n--)
    {
      cin >> a;
      s.erase(abs(a-temp));
      temp=a;
    }

    if(s.size()==0) cout << "Jolly\n";
    else cout << "Not jolly\n";
  }
  
  return 0;
}
