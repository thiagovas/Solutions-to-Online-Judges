#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <algorithm>
#include <locale>
#include <vector>
#include <map>
#include <set>
using namespace std;

#define endl "\n"
#define EPS 1e-8
typedef long long int ll;

typedef struct sPoint{double x, y;  sPoint(){} sPoint(double _x, double _y){x=_x;  y=_y;}} point;
typedef struct sLine{point a, b; sLine(point _a, point _b){a=_a;  b=_b;}} line;
double tPoints[4][4]={{-0.5+EPS, 0.5-EPS, 0.5-EPS, 0.5-EPS},
                      {-0.5+EPS, 0.5-EPS, -0.5+EPS, -0.5+EPS},
                      {0.5-EPS, 0.5-EPS, 0.5-EPS, -0.5+EPS},
                      {-0.5+EPS, -0.5+EPS, 0.5-EPS, -0.5+EPS}};


map<char, sPoint> keyboard;
map<char, vector<line> > boarders;
double charDist[26][26];

int cross(point a, point b, point c)
{
    double val = (b.y - a.y) * (c.x - b.x) -
              (b.x - a.x) * (c.y - b.y);
    
    if (val < EPS && val > -EPS) return 0;  // colinear
    return (val > EPS)? 1: 2; // clock or counterclock wise
}

double sqDist(point a, point b)
{
    a.x-=b.x;  a.y-=b.y;
    return (a.x*a.x)+(a.y*a.y);
}

bool crossLine(line a, line b)
{
    int o1 = cross(a.a, a.b, b.a);
    int o2 = cross(a.a, a.b, b.b);
    int o3 = cross(b.a, b.b, a.a);
    int o4 = cross(b.a, b.b, a.b);
    
    return (o1 != o2 && o3 != o4);
}

bool ehSubseq(string s, string v)
{
    int i=0, j=0;
    while(i < s.size() && j < v.size())
        if(s[i++]==v[j]) j++;
    return j==v.size();
}

bool crossBoarder(line l, char a)
{
    vector<line> v=boarders[a];
    for(unsigned int i = 0; i < v.size(); i++)
        if(crossLine(l, v[i])) return true;
    return false;
}

char origin;

bool comp(char a, char b)
{
    int ori = origin-'A';
    int aa=a-'A', bb=b-'A';
    return charDist[ori][aa] < charDist[ori][bb];
}

string getStringPath(char a, char b)
{
    line l = sLine(keyboard[a], keyboard[b]);
    vector<char> v;
    
    for(int i = 'A'; i <= 'Z'; i++)
    {
        if(i==a || i==b) continue;
        if(crossBoarder(l, i)) v.push_back(i);
    }
    origin=a;
    sort(v.begin(), v.end(), comp);
    string resp;
    for(unsigned int i = 0; i < v.size(); i++)
        resp+=v[i];
    resp = a+resp+b;
    return resp;
}

string expand(string s)
{
    string result;
    for(unsigned int i=1; i < s.size(); i++)
    {
        result += getStringPath(s[i-1], s[i]);
        result=result.substr(0, result.size()-1);
    }
    return result+*s.rbegin();
}


string dic[1000];
int main()
{
    ios::sync_with_stdio(false);  cin.tie(0); cout.tie(0);
    int t, n; char op='A';
    string poly;
    
    /* Filling keyboard */
    for(int i=2; i < 7; i++)
        keyboard[op++] = sPoint(i, 4);
    for(int j = 3; j > 0; j--)
        for(int i = 1; i < 8; i++)
            keyboard[op++] = sPoint(i, j);
     
    /* Preprocessing charDist */
    for(int i = 0; i < 26; i++)
        for(int j = i; j < 26; j++)
            charDist[i][j] = charDist[j][i] = sqDist(keyboard['A'+i], keyboard['A'+j]);
    
    for(int i = 'A'; i <= 'Z'; i++)
    {
        vector<line> newLine;
        for(int j=0; j < 4; j++)
            newLine.push_back(sLine(sPoint(keyboard[i].x+tPoints[j][0], keyboard[i].y+tPoints[j][1]),
                                    sPoint(keyboard[i].x+tPoints[j][2], keyboard[i].y+tPoints[j][3])));
        boarders[i]=newLine;
    }
    /* What a fucking preprocessing */
    
    cin >> t;
    while(t--)
    {
        cin >> n >> poly;
        for(int i = 0; i < n; i++) cin >> dic[i];
        poly = expand(poly);
        bool foi=false;
        for(int i=0; i < n; i++)
        {
            if(ehSubseq(poly, dic[i]))
            {
                cout << dic[i] << endl;
                foi=true; break;
            }
        }
        if(!foi) cout << "NO SOLUTION\n";
    }

    return 0;
}
