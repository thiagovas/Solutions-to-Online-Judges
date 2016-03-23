#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long int ll;

int test(int n, int m)
{
  vector<int> v(n-1);
  for(int i = 0; i < n-1; i++) v[i]=i+2;
  
  int index=0, c=0;
  while(v.size())
  {
    index = (index+m-1)%v.size(); c++;
    if(v[index] == 13) return c;
    v.erase(v.begin()+index);
  }
  return 0;
}

int main()
{
  ios::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
  
  int n;
  
  while(true)
  {
    cin >> n;
    if(not cin) break;
    if(n==0) break;
    
    int maxm=0, maxdist=0, temp;
    for(int i = 1; i <= 10*n; i++)
    {
      if(maxdist < (temp=test(n, i)))
      {
        maxdist = temp;
        maxm=i;
      }
    }
    cout << maxm << endl;
  }
  
  return 0;
}
