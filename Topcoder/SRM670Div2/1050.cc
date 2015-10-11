#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <utility>
#include <map>
#include <queue>
#include <stack>
#include <set>
using namespace std;

class Treestrat {
    private:
        typedef struct sNode{
            int index, minib;
            bool ehb;
            sNode(int _i, int _m, bool eh)
            { index=_i; minib=_m; ehb=eh; }
        } node;
        
        vector<node> vNodes;
        vector<vector<int> > graph;
        
        void countb(int ib) // index B
        {
            queue<pair<int, int> > q;
            vector<bool> visited(graph.size(), false);
            pair<int, int> atual;
            q.push(make_pair(ib, 0));
            
            while(!q.empty())
            {
                atual = q.front();
                q.pop();
                if(visited[atual.first]) continue;
                visited[atual.first]=true;
                vNodes[atual.first].minib = min(vNodes[atual.first].minib, atual.second);
                for(int i = 0; i < graph[atual.first].size(); i++)
                    q.push(make_pair(graph[atual.first][i], atual.second+1));
            }
        }
        
        int counta(int ia) // index A
        {
            queue<pair<int, int> > q;
            vector<bool> visited(graph.size(), false);
            pair<int, int> atual;
            q.push(make_pair(ia, 0));
            int ra=0;
            
            while(!q.empty())
            {
                atual=q.front(); q.pop();
                if(visited[atual.first]) continue;
                visited[atual.first]=true;
                if(vNodes[atual.first].ehb) continue;
                if(vNodes[atual.first].minib <= atual.second) continue;
                ra = max(ra, vNodes[atual.first].minib);
                for(int i = 0; i < graph[atual.first].size(); i++)
                    q.push(make_pair(graph[atual.first][i], atual.second+1));
            }
            return ra;
        }
        
    public:
        int roundcnt(vector<int> tree, vector<int> A, vector<int> B)
        {
            graph.resize(tree.size()+1);
            
            for(int i = 0; i < tree.size()+1; i++)
                this->vNodes.push_back(sNode(i, 100, false));
            
            for(int i = 0; i < tree.size(); i++)
            {
                graph[i+1].push_back(tree[i]);
                graph[tree[i]].push_back(i+1);
            }
            
            for(int i = 0; i < B.size(); i++)
            {
                countb(B[i]);
                vNodes[B[i]].ehb=true;
            }
            
            int mini=100;
            for(int i = 0; i < A.size(); i++)
                mini = min(mini, counta(A[i]));
            return mini;
        }
};
