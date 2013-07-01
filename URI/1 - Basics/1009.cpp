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
    string nome;
    double salary, total;
    
    cin >> nome;
    cin >> salary >> total;
    
    printf("TOTAL = R$ %.2lf\n", salary + total*0.15);
    
    return 0;
}
