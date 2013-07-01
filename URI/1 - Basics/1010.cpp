#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <functional>
#include <utility>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    int c1, c2;
    double soma1, soma2;
    
    cin >> c1;
    cin >> c1;
    cin >> soma1;
    
    cin >> c2;
    cin >> c2;
    cin >> soma2;
    
    printf("VALOR A PAGAR: R$ %.2lf\n", soma1*c1 + soma2*c2); 
    
    return 0;
}
