#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <sstream>
using namespace std;

string itos(int i)
{
    stringstream s;
    s << i;
    return s.str();
}

long long int dectobin(long long int dec)
{
    if(dec == 0) return 0;
    else if(dec == 1) return 1;
    
    long long int n = 0;
    int cont = 0;
    while(dec > 0)
    {
        n += pow(10, cont++)*(dec%2);
        dec/=2;
    }
    return n;
}

long long int bintodec(long long int bin)
{
    if(bin == 0) return 0;
    else if(bin == 1) return 1;
    
    long long int n = 1;
    long long int dec = 0;
    while(bin > 0)
    {
        dec += (bin%10)*n;
        bin /= 10;
        n<<=1;
    }
    return dec;
}

long long int hextobin(string hex)
{
    long long int n = 0;
    int cont = 0, value = 0;
    for(int i = hex.length()-1; i >= 0; i--)
    {
        if(hex[i] == 'a')
            value = 10;
        else if(hex[i] == 'b')
            value = 11;
        else if(hex[i] == 'c')
            value = 12;
        else if(hex[i] == 'd')
            value = 13;
        else if(hex[i] == 'e')
            value = 14;
        else if(hex[i] == 'f')
            value = 15;
        else
            value = ((int)hex[i])-48;
        n += pow(10, cont)*dectobin(value);
        cont += 4;
    }
    return n;
}

string bintohex(long long int bin)
{
    if(bin == 0) return "0";
    
    string result = "";
    long long int atual = 0;
    while(bin > 0)
    {
        atual = bintodec(bin%10000);
        switch(atual)
        {
            case 10:
                result.append("a");
                break;
            case 11:
                result.append("b");
                break;
            case 12:
                result.append("c");
                break;
            case 13:
                result.append("d");
                break;
            case 14:
                result.append("e");
                break;
            case 15:
                result.append("f");
                break;
            default:
                result.append(itos(atual));
                break;
        }
        bin /= 10000;
    }
    reverse(result.begin(), result.end());
    return result;
}

long long int hextodec(string hex)
{
    if(hex == "0") return 0;
    return bintodec(hextobin(hex));
}

string dectohex(long long int dec)
{
    if(dec == 0) return "0";
    return bintohex(dectobin(dec));
}

int main()
{
    int n, i = 1;
    string base, input;
    
    scanf("%d", &n);
    while(n-- > 0)
    {
        cin >> input;
        cin >> base;
        
        printf("Case %d:\n", i++);
        if(base == "bin")
        {
            cout << bintodec(atoi(input.c_str())) << " dec\n";
            cout << bintohex(atoi(input.c_str())) << " hex\n";
        }
        else if(base == "hex")
        {
            cout << hextodec(input) << " dec\n";
            cout << hextobin(input) << " bin\n";
        }
        else
        {
            cout << dectohex(atoi(input.c_str())) << " hex\n";
            cout << dectobin(atoi(input.c_str())) << " bin\n";
        }
        printf("\n");
    }
    return 0;
}
