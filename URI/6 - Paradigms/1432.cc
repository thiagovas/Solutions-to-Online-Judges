#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
typedef long long int ll;
typedef long double ld;

string s;

bool valid(int n)
{
  if(n < 3) return true;
  for(int t = 1; t <= n/3; t++)
  {
    bool eh=false;
    for(int i = 0; i < t; i++)
    {
      if(not(s[n-i-1] == s[n-i-1-t] && s[n-i-1] == s[n-i-1-2*t]))
      {
        eh=true; break;
      }
    }
    if(not eh) return false;
  }
  return true;
}

int backtrack(int i)
{
  if(i==s.size()) return 1;
  
  int ret=0;
  if(s[i]=='*')
  {
    s[i]='0';
    if(valid(i+1))
      ret += backtrack(i+1);
    
    s[i]='1';
    if(valid(i+1))
      ret += backtrack(i+1);
    s[i]='*';
  }
  else
  {
    if(valid(i+1)) return backtrack(i+1);
    else return 0;
  }
  return ret;
}


int main()
{
  ios::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
  int n, teste=1;
  
  while(true)
  {
    cin >> n;
    if(not cin) break;
    if(n==0) break;
    
    cin >> s;
    cout << "Case " << teste++ << ": " << backtrack(0) << endl;
  }
  
  return 0;
}
