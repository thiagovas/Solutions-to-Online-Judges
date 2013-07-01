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

double distDoisPontos(double xa, double ya, double xb, double yb)
{
    return sqrt((xa-xb)*(xa-xb) + (ya-yb)*(ya-yb));
}

int main()
{
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    printf("%.4lf\n", distDoisPontos(a, b, c, d));
    return 0;
}
