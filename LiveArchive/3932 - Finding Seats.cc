#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF 0x3f3f3f3f
typedef long long int ll;

char tab[500][500];
int prefix[500][500];

int main()
{
  ios::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
  
  int r, c, k;
  
  while(true)
  {
    cin >> r >> c >> k;
    if(not cin) break;
    if(r==0 && c==0 && k==0) break;
    
    memset(prefix, 0, sizeof(prefix));
    for(int i = 0; i < r; i++)
      for(int j = 0; j < c; j++)
      {
        cin >> tab[i][j];
        prefix[i][j+1]=prefix[i][j];
        if(tab[i][j]=='.') prefix[i][j+1]++;
      }
    
    int mini=INF;
    for(int i = 0; i <= c; i++)
    {
      for(int j = i+1; j <=c; j++)
      {
        int b=0, l=0, e=0;
        while(l < r)
        {
          e+=prefix[l][j]-prefix[l][i];
          while(e >= k)
          {
            mini = min(mini, (j-i)*(l-b+1));
            e-=prefix[b][j]-prefix[b][i];
            b++;
          }
          l++;
        }
      }
    }
    cout << mini << endl;
  }
  
  return 0;
}
