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

class Drbalance {
    public:
        int count(string s)
        {
            int r=0, c=0;
            for(int i=0; i < s.size(); i++)
            {
                if(s[i]=='+') r++;
                else r--;
                if(r < 0) c++;
            }
            return c;
        }
        
        int lesscng(string s, int k)
        {
            int c=0;
            while(count(s) > k)
            {
                for(int i = 0; i < s.size(); i++)
                    if(s[i]=='-')
                    {
                        s[i]='+';
                        break;
                    }
                c++;
            }
            return c;
        }
};
