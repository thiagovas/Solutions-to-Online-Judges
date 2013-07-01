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
    int a, b, c;
    
    cin >> a >> b >> c;
    printf("%d eh o maior\n", max(a, max(b, c)));
    return 0;
}
