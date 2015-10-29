#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <cstring>
using namespace std;

#define endl "\n"
typedef long long int ll;

int main()
{
    ios::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);

    int t;
    string s;

    cin >> t;
    while(t--)
    {
        cin >> s;
        int c=0;
        int x=0, y=0;
        for(int i = 0; i < s.size(); i++)
            if(s[i]=='?') c++;
            else if(s[i]=='U') y++;
            else if(s[i]=='D') y--;
            else if(s[i]=='L') x--;
            else x++;
        cout << x-c << " " << y-c << " " << x+c << " " << y+c << endl;
    }

    return 0;
}
