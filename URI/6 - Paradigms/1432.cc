#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF 0x3f3f3f3f
typedef long long int ll;

string op[] = {"001", "010", "100", "011", "101", "110"};
vector<string> vs;

bool check(string s)
{
  int sz=s.size();
  for(int i = 0; i < 3; i++)
  {
    for(int t = 1; t <= (s.size()-i)/3; t++)
    {
      int k=0;
      for(k = 0; k < t; k++)
      {
        if(not (s[sz-i-1-k]==s[sz-i-1-k-t] && s[sz-i-1-k]==s[sz-i-1-k-2*t]))
          break;
      }
      if(k==t) return false;
    }
  }
  return true;
}

void gen(string s)
{
  if(s.size() <= 30)
  {
    vs.push_back(s);
    if(s.size() == 30) return;
  }
  
  if(check(s+"0")) gen(s+"0");
  if(check(s+"1")) gen(s+"1");
}

int main()
{
  ios::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
  
  int n, teste=1;
  string s;
  
  for(int i = 0; i < 6; i++)
    gen(op[i]);
  
  while(true)
  {
    cin >> n;
    if(not cin) break;
    if(n==0) break;
    
    set<string> result;
    cin >> s;
    for(int i = 0; i < vs.size(); i++)
    {
      bool eh=true;
      if(vs[i].size() < s.size()) continue;
      for(int j = 0; j < s.size(); j++)
      {
        if(s[j]!='*')
        {
          if(s[j]!=vs[i][j])
          {
            eh=false;
            break;
          }
        }
      }
      if(eh) result.insert(vs[i].substr(0, s.size()));
    }
    cout << "Case " << teste++ << ": " << result.size() << endl;
  }
  
  return 0;
}
