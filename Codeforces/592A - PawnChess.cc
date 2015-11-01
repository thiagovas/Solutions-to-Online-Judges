#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <utility>
using namespace std;

#define endl "\n"
#define INF 0x3f3f3f3f
typedef long long int ll;

char tab[8][8];

//pra cima
int andaw(int r, int c)
{
  for(int i = r-1; i >=0; i--)
    if(tab[i][c]!='.') return INF;
  return r;
}

//pra baixo
int andab(int r, int c)
{
  for(int i = r+1; i < 8; i++)
    if(tab[i][c]!='.') return INF;
  return 7-r;
}

int main()
{
  ios::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
  int t[8];
  memset(t, 0, 8);

  for(int i = 0; i < 8; i++)
    for(int j = 0; j < 8; j++)
      cin >> tab[i][j];

  int miniw=INF, minib=INF;
  for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      if(tab[i][j]=='W') miniw = min(miniw, andaw(i, j));
      else if(tab[i][j]=='B') minib = min(minib, andab(i, j));
    }
  }
  if(miniw==minib) cout << "A\n";
  else cout << (miniw<minib?"A":"B") << endl;
  return 0;
}
