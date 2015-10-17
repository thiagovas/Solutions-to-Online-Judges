#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

string inverter(string a)
{
    string result;
    for(int i = a.length()-1; i >= 0; i--)
        result.push_back(a[i]);
    return result;
}

int main()
{
    int n;
    string palavras, proibida;
    
    cin >> n;
    while(n-- > 0)
    {
        cin >> proibida >> palavras;
        palavras += palavras;
        
        if(palavras.find(proibida) != std::string::npos || inverter(palavras).find(proibida) != std::string::npos)
            cout << "S\n";
        else
            cout << "N\n";
    }
    
    return 0;
}
