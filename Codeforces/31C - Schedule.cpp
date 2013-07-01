#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

typedef struct{
    int index, inicio, fim, tam, interrupt;
} group;

int main()
{
    int l, r;
    int n, temp, cont = 1, numcolisoes = 0;
    vector<group> g;
    
    cin >> n;
    temp = n;
    g.clear();
    while(temp-- > 0)
    {
        cin >> l >> r;
        
        group gtemp;
        gtemp.index = cont++;
        gtemp.inicio = l;
        gtemp.fim = r;
        gtemp.tam = l-r;
        gtemp.interrupt = 0;
        
        g.push_back(gtemp);
    }
    
    for(vector<group>::iterator it = g.begin(); it != g.end(); it++)
    {
        for(vector<group>::iterator jt = g.begin(); jt != g.end(); jt++)
        {
            if(it->index == jt->index) continue;
            if(it->fim > jt->inicio && it->inicio < jt->fim)
            {
                it->interrupt++;
                jt->interrupt++;
                numcolisoes++;
            }
        }
    }
    
    cont = 0;
    if(numcolisoes != 0)
    {
        multiset<int> resp;
        for(vector<group>::iterator it = g.begin(); it != g.end(); it++)
        {
            if(it->interrupt == numcolisoes)
            {
                resp.insert(it->index);
            }
            else if(it->interrupt > 0)
                cont++;
        }
        if(resp.size() == 0 && cont > 0)
        {
            printf("0\n");
            return 0;
        }
        else
        {
            printf("%lu\n", resp.size());
            printf("%d", (*resp.begin()));
            for(multiset<int>::iterator it = ++resp.begin(); it != resp.end(); it++)
                printf(" %d", *it);
            printf("\n");
            
        }
    }
    else
    {
        printf("%lu\n", g.size());
        printf("%d", g.begin()->index);
        for(vector<group>::iterator it = ++g.begin(); it != g.end(); it++)
            printf(" %d", it->index);
        printf("\n");
    }
    return 0;
}
