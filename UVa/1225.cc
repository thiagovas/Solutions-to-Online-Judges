// UVa 1225 - Digit Counting
#include <bits/stdc++.h>
using namespace std;

// Keeps the number of occurences for each digit...
int occ[10];

void countit(int n)
{
  for(int i = 1; i <= n; i++)
  {
    int tmp=i;
    while(tmp != 0)
    {
      occ[tmp%10]++;
      tmp/=10;
    }
  }
}

int main()
{
  int t, n;
  
  cin >> t;
  while(t--)
  {
    cin >> n;
    memset(occ, 0, sizeof(occ));
    countit(n);

    cout << occ[0];
    for(int i = 1; i < 10; i++)
      cout << " " << occ[i];
    cout << endl;
  }
  
  return 0;
}
