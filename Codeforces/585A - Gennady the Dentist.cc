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
typedef long long int ll;

typedef struct sChild{ ll v, d, p; sChild(ll _v, ll _d, ll _p){v=_v;d=_d;p=_p;}} child;

int main()
{
    ios::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
    ll n, v, d, p;
    vector<bool> jafoi;
    vector<child> vc;
    
    cin >> n;
    jafoi.assign(n, false);
    while(n--)
    {
        cin >> v >> d >> p;
        vc.push_back(sChild(v, d, p));
    }
    
    vector<int> resp;
    for(int i = 0; i < vc.size(); i++)
    {
        if(jafoi[i]) continue;
        resp.push_back(i+1);
        for(int j=i+1; j < vc.size() && vc[i].v!=0; j++)
            if(!jafoi[j])
            {
                vc[j].p-=vc[i].v;
                vc[i].v--;
            }
        
        d=0;
        for(int j=i+1; j < vc.size(); j++)
        {
            if(jafoi[j]) continue;
            vc[j].p-=d;
            if(vc[j].p<0)
            {
                d+=vc[j].d;
                jafoi[j]=true;
            }
        }
        jafoi[i]=true;
    }
    cout << resp.size() << endl;
    cout << resp[0];
    for(int i = 1; i < resp.size(); i++)
        cout << " " << resp[i];
    cout << endl;

    return 0;
}
