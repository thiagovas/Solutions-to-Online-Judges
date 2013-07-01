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
    double a, b, c;
    
    cin >> a >> b >> c;
    
    printf("TRIANGULO: %.3lf\n", (a*c)/2.0);
    printf("CIRCULO: %.3lf\n", c*c*3.14159);
    printf("TRAPEZIO: %.3lf\n", ((a + b)*c)/2.0);
    printf("QUADRADO: %.3lf\n", b*b);
    printf("RETANGULO: %.3lf\n", a*b);
    return 0;
}
