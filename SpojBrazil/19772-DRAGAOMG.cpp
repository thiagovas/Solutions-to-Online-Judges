#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <locale>
#include <utility>
#include <queue>
#include <stack>
using namespace std;

#define endl "\n"
typedef long long int ll;

int bfs(vector<vector<int> > &graph)
{
    pair<int, int> atual;
    queue<pair<int, int> > q;
    vector<bool> visited(graph.size(), false);
    
    q.push(make_pair(100, 0));
    while(!q.empty())
    {
        atual = q.front(); q.pop();
        if(visited[atual.first]) continue;
        visited[atual.first]=true;
        
        if(atual.first == 0) return atual.second;
        
        for(unsigned int i = 0; i < graph[atual.first].size(); i++)
            q.push(make_pair(graph[atual.first][i], atual.second+1));
    }
    return -1;
}

void addEdge(vector<vector<int> > &graph, queue<int> &q, int atual, int n, int c)
{
    
    if(atual-c < 0) return;
    if(atual+n-c > 1000)
        graph[atual].push_back(1000);
    else
    {
        if(atual-c==0) graph[atual].push_back(0);
        else
        {
            graph[atual].push_back(atual+n-c);
            q.push(atual+n-c);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
    int g, input;
    vector<int> c, n;
    vector<vector<int> > graph;

    while(true)
    {
        cin >> g;
        if(not cin) break;
        if(g==0) break;
        
        graph.clear(); graph.resize(1001);
        c.clear();  n.clear();
        for(int i = 0; i < g; i++)
        {
            cin >> input;
            c.push_back(input);
        }

        while(g--)
        {
            cin >> input;
            n.push_back(input);
        }
        
        set<int> jafoi;
        queue<int> q;
        q.push(100);
        while(!q.empty())
        {
            int atual = q.front(); q.pop();
            if(jafoi.find(atual) != jafoi.end()) continue;
            jafoi.insert(atual);
            
            for(unsigned int i = 0; i < c.size(); i++)
                addEdge(graph, q, atual, n[i], c[i]);
        }
        
        int ret = bfs(graph);
        if(ret==-1) cout << "cavaleiro morreu\n";
        else cout << ret << endl;
    }
    
    
    
    return 0;
}
