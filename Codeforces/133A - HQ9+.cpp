#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    string entrada;
    int length = 0;
    cin >> entrada;
    length = entrada.length();
    
    for(int i = 0; i < length; i++)
    {
        if(entrada[i] == 'H' || entrada[i] == 'Q' || entrada[i] == '9')
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
