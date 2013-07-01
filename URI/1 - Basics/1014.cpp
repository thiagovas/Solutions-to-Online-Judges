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
    int km;
    double fuel;
    
    cin >> km;
    cin >> fuel;
    
    printf("%.3lf km/l\n", km/fuel);
    return 0;
}
