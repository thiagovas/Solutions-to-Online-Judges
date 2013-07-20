#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comparar(int i, int j)
{
    return j < i;
}

int main()
{
    int cenarios, nStamps, nFriends, temp, cont;
    vector<int> stamps;
    
    cin >> cenarios;
    cont = 0;
    while(cenarios-- > 0)
    {
        cont++;
        cin >> nStamps >> nFriends;
        while(nFriends-- > 0)
        {
            cin >> temp;
            stamps.push_back(temp);
        }
        
        sort(stamps.begin(), stamps.end(), comparar);
        temp = 0;
        nFriends = 0;
        for(vector<int>::iterator i = stamps.begin(); i != stamps.end(); i++)
        {
            if(temp >= nStamps) break;
            temp += *i;
            nFriends++;
        }
        if(temp >= nStamps)
        {
            cout << "Scenario #" << cont << ":\n" << nFriends << "\n\n";
        }
        else
        {
            cout << "Scenario #" << cont << ":\n" << "impossible\n\n";
        }
        stamps.clear();
    }
    return 0;
}
