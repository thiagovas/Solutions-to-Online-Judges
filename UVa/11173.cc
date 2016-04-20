#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long int ll;


int main()
{
  ios::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
  int t, n, k;

  cin >> t;
  while(t--)
  {
    cin >> n >> k;
    cout << (k^(k>>1)) << endl;
  }
  
  return 0;
}
