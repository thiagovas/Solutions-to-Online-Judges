#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define PII pair<int, int>
#define PLL pair<ll, ll>
typedef long long int ll;
typedef long double ld;


int main()
{
  ll t, n, price;
  char a;
  string line;
  
  scanf("%lld", &t);
  while(t-- > 0)
  {
    map<char, int> mp;
    scanf("%lld%*c", &n);
    while(n-- > 0)
    {
      scanf("%c %lld%*c", &a, &price);
      mp[a] = price;
    }
    scanf("%lld", &n);
    price=0;
    getchar();
    while(n-- > 0)
    {
      getline(std::cin, line);
      for(int i = 0; i < line.size(); i++) price += mp[line[i]];
    }
    cout << price/100 << "." << ((price%100 < 10) ? "0" : "") << price%100 << "$\n";
  }
  
  return 0;
}
