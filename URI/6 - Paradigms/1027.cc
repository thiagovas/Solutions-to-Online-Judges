#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long int ll;

int main()
{
  ios::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
  int n;
  vector<pair<int, int> > v, pd;
  
  while(true)
  {
    cin >> n;
    if(not cin) break;
    if(n==0) break;
    
    v.clear();  pd.clear();  pd.resize(n, make_pair(1, 1));
    while(n-- > 0)
    {
      pair<int, int> neue;
      cin >> neue.first >> neue.second;
      v.push_back(neue);
    }
    
    int maxi=1;
    sort(v.begin(), v.end());
    for(int i = 1; i < v.size(); i++)
    {
      for(int j = i-1; j >= 0; j--)
      {
        if(v[i].first == v[j].first) continue;
        if(v[j].second == v[i].second+2)
          pd[i].second = max(pd[i].second, pd[j].first+1);
        else if(v[j].second == v[i].second-2)
          pd[i].first = max(pd[i].first, pd[j].second+1);
      }
      maxi = max(maxi, pd[i].first);
      maxi = max(maxi, pd[i].second);
    }
    cout << maxi << endl;
  }

  return 0;
}
