#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;

map<int, int> cores;
map<int, set<int> > card;

bool comp(int i, int j)
{
    return i < j;
}

int Verificar(vector<vector<int> > *grafo)
{
    unsigned int atual = 0, maximo = 0, corMin = 10000000;
    for(vector<vector<int> >::iterator it = grafo->begin(); it != grafo->end(); it++)
    {
        for(vector<int>::iterator jt = it->begin(); jt != it->end(); jt++)
            if(*jt != cores[atual]) card[cores[atual]].insert(*jt);
        
        if(card[cores[atual]].size() > maximo)
        {
            maximo = card[cores[atual]].size();
            corMin = cores[atual];
        }
        else if(card[cores[atual]].size() == maximo)
        {
            if(cores[atual] <= corMin)
                corMin = cores[atual];
        }
        atual++;
    }
    return corMin;
}

int main()
{
    vector<vector<int> > grafo;
    int n, m, temp, input, input2;
    set<int> setBase;
    
    scanf("%d %d", &n, &m);
    temp = 0;
    grafo.resize(n);
    
    while(temp < n)
    {
        scanf("%d", &input);
        cores.insert(make_pair(temp, input));
        card[input] = setBase;
        temp++;
    }
    
    while(m-- > 0)
    {
        scanf("%d %d", &input, &input2);
        grafo[input-1].push_back(cores[input2-1]);
        grafo[input2-1].push_back(cores[input-1]);
    }
    
    printf("%d\n", Verificar(&grafo));
    
    return 0;
}
