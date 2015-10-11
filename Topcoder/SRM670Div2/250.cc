#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
using namespace std;

class Cdgame{
    public:
        int rescount(vector<int> a, vector<int> b)
        {
            set<int> s;
            int s1=0, s2=0;
            for(int i=0; i < a.size(); i++) s1+=a[i];
            for(int i=0; i < b.size(); i++) s2+=b[i];
            for(int i = 0; i < a.size(); i++)
                for(int j = 0; j < b.size(); j++)
                    s.insert((s2-b[j]+a[i])*(s1-a[i]+b[j]));
            return s.size();
        }
};
