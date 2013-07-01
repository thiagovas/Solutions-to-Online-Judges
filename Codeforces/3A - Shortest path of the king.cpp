#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    char input1[3], input2[3];
    string h, v;
    int dif1, dif2, i;
    
    cin >> input1;
    cin >> input2;
    
    dif1 = (int)input1[0] - (int)input2[0];
    dif2 = input1[1] - input2[1];
    
    if(dif1 > 0) h = "L";
    else h = "R";
    
    if(dif2 > 0) v = "D";
    else v = "U";
    
    dif1 = abs(dif1);
    dif2 = abs(dif2);
    
    if(dif1 > dif2)
    {
        cout << dif1 << endl;
        
        for(i = 0; i < dif2; i++)
            cout << h << v << endl;
        while(i++ < dif1)
            cout << h << endl;
    }
    else
    {
        cout << dif2 << endl;
        for(i = 0; i < dif1; i++)
            cout << h+v << endl;
        while(i++ < dif2)
            cout << v << endl;
    }
    
    return 0;
}
