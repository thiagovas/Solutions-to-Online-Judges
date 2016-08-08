#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long int ll;

int main()
{
  ios::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
  
  ll n, a, tmp;
  
  while(true)
  {
    cin >> n >> a;
    if(not cin) break;
    if(n==0 && a==0) break;
    
    vector<double> v, prefix(1, 0);
    double sum=0;
    while(n--)
    {
      cin >> tmp;
      v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++)
    {
      sum += v[i];
      prefix.push_back(sum);
    }
    double lim=*v.rbegin();
    if(sum == a) cout << ":D\n";
    else if(sum < a) cout << "-.-\n";
    else
    {
      int c=0;
      double b=0, e=lim+1, mid=0;
      while(c++ < 10000)
      {
        mid = (b+e)/2;
        int pos = upper_bound(v.begin(), v.end(), mid)-v.begin();
        double area = sum-mid*(v.size()-pos)-prefix[pos];
        if(area > a) b=mid;
        else e=mid;
      }
      cout << std::fixed << std::setprecision(4) << mid << endl;
    }
  }
  
  return 0;
}
