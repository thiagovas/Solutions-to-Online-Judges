#include <bits/stdc++.h>
using namespace std;

char op[] = {'N', 'O', 'P'};

bool valid(vector<char> &vs, int index)
{
  for(int i = 1; i <= (index+1)/2; i++)
  {
    bool equal=true;
    for(int j = index; j > index-i; j--)
    {
      if(vs[j]!=vs[j-i])
      {
        equal=false;
        break;
      }
    }
    if(equal) return false;
  }
  return true;
}

bool backtracking(vector<char> &vs, int index)
{
  if(index==5010) return true;
  
  for(int i = 0; i < 3; i++)
  {
    vs[index]=op[i];
    if(valid(vs, index))
      if(backtracking(vs, index+1)) return true;
  }
  return false;
}

int main()
{
  ios::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
  
  int n;
  string s = "NONPNOPNPONOPNONPNOP";
  vector<char> vs(5100, 'N');
  
  for(unsigned i = 0; i < s.size(); i++) vs[i] = s[i];
  backtracking(vs, s.size());
  
  while(true)
  {
    cin >> n;
    if(not cin) break;
    if(n==0) break;
    for(int i = 0; i < n; i++) cout << vs[i];
    cout << endl;
  }
  
  return 0;
}
