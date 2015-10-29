#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <locale>
#include <utility>
using namespace std;

#define endl "\n"
#define MOD 1000000007
typedef long long int ll;

ll calc(string s, int begin, int end)
{
    if(begin==end) return 1;
    int last=begin;
    ll resp=1;
    
    for(int i = begin+1; i <= end; i++)
    {
        if(s[i]!='?')
        {
            if(s[i]==s[last])
            {
                last=i;
                continue;
            }
            resp*=(i-last);
            resp%=MOD;
            last=i;
        }
    }
    return resp;
}

int main()
{
    ios::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
    int t;
    string s;
    
    cin >> t;
    while(t--)
    {
        cin >> s;
        if(s.size()==1||s.size()==2)
            cout << 1 << endl;
        else
        {
            int begin=0, end=0;
            for(int i = 0; i < s.size(); i++)
                if(s[i]!='?')
                { begin=i;  break; }
            
            for(int i = s.size()-1; i >= 0; i--)
                if(s[i]!='?')
                { end=i; break; }
            cout << calc(s, begin, end) << endl;
        }
    }
    
    return 0;
}
