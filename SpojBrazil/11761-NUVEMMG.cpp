#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <locale>
#include <utility>
#include <queue>
#include <stack>
using namespace std;

#define endl "\n"
#define MAX 500
#define INF 0x3f3f3f3f
typedef long long int ll;

int m[MAX][MAX];

int f(int i, int j, vector<pair<int, int> > v)
{
    int k=1;
    int mini=INF;
    while(i-k >= 0)
    {
        mini = min(mini, m[i-k][j-1] + k*v[i].second);
        k++;
    }
    return mini;
}

int dp(vector<pair<int, int> > v, int l)
{
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            m[i][j]=INF;
    
    for(int i = 0; i < v.size(); i++)
        m[i][0] = (i+1)*v[i].second;

    for(int j = 1; j < l; j++)
        for(int i = j; i < v.size(); i++)
            m[i][j] = f(i, j, v);
    return m[v.size()-1][l-1];
}

int main()
{
    //ios::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
    
    int k, l, d, p;
    vector<pair<int, int> > v;

    while(true)
    {
        cin >> k >> l;
        if(not cin) break;
        if(k == 0 && l == 0) break;
        
        v.clear();
        while(k--)
        {
            cin >> d >> p;
            v.push_back(make_pair(d, p));
        }
        sort(v.begin(), v.end());
        cout << dp(v, l) << endl;
    }
    
    return 0;
}
