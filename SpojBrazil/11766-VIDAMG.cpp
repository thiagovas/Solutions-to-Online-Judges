#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <locale>
using namespace std;

#define endl "\n"
typedef long long int ll;
typedef struct sPoint{int x, y; sPoint(int _x, int _y){x=_x;y=_y;}} point;

point p[8] = {sPoint(-1, -1), sPoint(-1, 0), sPoint(1, 1), sPoint(1, 0), sPoint(0, -1), sPoint(0, 1), sPoint(-1, 1), sPoint(1, -1)};
map<pair<int, int>, bool> s;

int count(int vx, int vy)
{
    int c=0;
    for(int i = 0; i < 8; i++)
        if(s.find(make_pair(vx+p[i].x, vy+p[i].y)) != s.end()) c++;
    return c;
}

int sim(int k)
{
    map<pair<int, int>, bool> temp;
    while(k--)
    {
        temp=s;
        for(map<pair<int, int>, bool>::iterator it = s.begin(); it != s.end(); it++)
        {
            // Dying
            int c=count(it->first.first, it->first.second);
            if(c < 2 || c > 3) temp.erase(make_pair(it->first.first, it->first.second));
            
            // Resurrect Like a Jesus
            for(int i = 0; i < 8; i++)
            {
                c=count(it->first.first+p[i].x, it->first.second+p[i].y);
                if(c==3) temp[make_pair(it->first.first+p[i].x, it->first.second+p[i].y)]=true;
            }
        }
        s=temp;
    }
    return s.size();
}

int main()
{
    ios::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
    int n, x, y;
    
    while(true)
    {
        cin >> n;
        if(not cin) break;
        if(n == 0) break;
        
        s.clear();
        while(n--)
        {
            cin >> x >> y;
            s[make_pair(x, y)]=true;
        }
        cin >> x;
        cout << sim(x) << endl;
        for(map<pair<int, int>, bool>::iterator it = s.begin(); it != s.end(); it++)
            cout << it->first.first << " " << it->first.second << endl;
    }

    return 0;
}
