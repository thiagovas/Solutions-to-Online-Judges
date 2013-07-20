#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <utility>
#include <stack>
#include <queue>
using namespace std;

bool dfs(vector<vector<int> > *grafo)
{
    stack<int> nodes;
    vector<bool> visited(grafo->size(), false);
    int atual = 0;
    
    for(unsigned int i = 0; i < grafo->size(); i++)
    {   
        if(!visited[i])
        {
            nodes.push(i);
            while(!nodes.empty())
            {
                atual = nodes.top();
                nodes.pop();
        
                if(visited[atual]) return false;
                visited[atual] = true;
        
                for(vector<int>::iterator it = (*grafo)[atual].begin(); it != (*grafo)[atual].end(); it++)
                    if(!visited[*it])
                        nodes.push(*it);
        
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<int> > grafo;
    int n, m;
    int i1, i2;
    
    scanf("%d %d", &n, &m);
    grafo.resize(n);
    
    while(m-- > 0)
    {
        scanf("%d %d", &i1, &i2);
        grafo[i1-1].push_back(i2-1);
        grafo[i2-1].push_back(i1-1);
    }
    
    if(dfs(&grafo))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
