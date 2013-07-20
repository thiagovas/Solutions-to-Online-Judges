#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <deque>
#include <queue>
#include <functional>
using namespace std;

bool visited[2000], part[2000];

bool bipartiteGraph(vector<vector<int> > *grafo, int tam)
{
    bool result = true;
    int atual;
    deque<int> q;
    
    for(int i = 0; i < tam; i++)
    {   
        visited[i] = false;
        part[i] = false;
    }
    
    for(int i = 0; i < tam; i++)
    {
        if(visited[i]) continue;
        
        q.clear();
        q.push_back(i);
        
        part[i] = true;
        while(!q.empty())
        {
            atual = q.front();
            q.pop_front();
            
            for(vector<int>::iterator it = (*grafo)[atual].begin(); it != (*grafo)[atual].end(); it++)
            {
                if((part[(*it)] == part[atual]) && visited[(*it)])
                {
                    result = false;
                    goto finishhim;
                }
                
                if(!visited[(*it)])
                {
                    part[(*it)] = !part[atual];   
                    q.push_back((*it));
                }
            }
            visited[atual] = true;
        }
    }
    finishhim:
    return result;
}

int main()
{
    vector<vector<int> > grafo;
    int n, numBugs, inter;
    int in1, in2;
    int cont = 0;
    
    cin >> n;
    while(n-- > 0)
    {
        scanf("%d", &numBugs);
        scanf("%d", &inter);
        grafo.clear();
        grafo.resize(numBugs);
        
        while(inter-- > 0)
        {
            scanf("%d", &in1);
            scanf("%d", &in2);
            grafo[in1-1].push_back(in2-1);
            grafo[in2-1].push_back(in1-1);
        }
        
        printf("Scenario #%d:\n", ++cont);
        if(bipartiteGraph(&grafo, numBugs))
            printf("No suspicious bugs found!\n");
        else
            printf("Suspicious bugs found!\n");
    }
    return 0;
}

