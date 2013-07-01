#include <iostream>
using namespace std;

int main()
{
    int peso;
    cin >> peso;
    if(peso == 2)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << (peso % 2 == 0 ? "YES" : "NO") << endl;
    }
    return 0;
}
