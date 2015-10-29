#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <locale>
#include <utility>
using namespace std;

#define endl "\n"
typedef long long int ll;

int main()
{
    ios::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
    int t, n, x, y, input, resp=0;
    
    
    cin >> t;
    while(t--)
    {
        cin >> n >> x >> y; 
        cin >> input;
        resp=0;
        if(input==x) resp |= 1;
        for(int i = 1; i < n-1; i++) cin >> input;
        cin >> input;
        if(input==y) resp|=2;
        switch(resp)
        {
            case 0:
                cout << "OKAY\n";
                break;
            case 1:
                cout << "EASY\n";
                break;
            case 2:
                cout << "HARD\n";
                break;
            case 3:
                cout << "BOTH\n";
                break;
        }
    }
    
    return 0;
}
