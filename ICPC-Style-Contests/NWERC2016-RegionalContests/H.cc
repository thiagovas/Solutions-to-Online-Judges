#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

ull to_ull(const string& s)
{
  int pow=0;
  ull resp=0;
  for(int i = s.size()-1; i >= 0; i--)
  {
    if(s[i] == '1') resp |= (1llu<<pow);
    pow++;
  }
  return resp;
}

ull conv(ull& a)
{
  a = a^(a>>32);
  a = a^(a>>16);
  a = a^(a>>8);
  a = a^(a>>4);
  a = a^(a>>2);
  a = a^(a>>1);
  return a;
}

int main()
{
  int n;
  string s, t;

  cin >> n >> s >> t;
  ull a = to_ull(s);
  ull b = to_ull(t);

  cout << conv(b)-conv(a)-1 << endl;
  
  return 0;
}
