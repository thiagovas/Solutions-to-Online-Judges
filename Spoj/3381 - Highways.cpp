#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

long long int dijkstra(vector<vector<pair<int, int> > > *a, int s, int e)
{
    priority_queue<pair<int, long long int>, vector<pair<int, long long int> >, greater<pair<int, long long int> > > q;
    pair<int, int> atual;
    long long int *pesos = (long long int*)calloc(a->size(), sizeof(long long int));
    long long int retorno = -1, soma;
    
    for(unsigned int i = 0; i < a->size(); i++)
        pesos[i] = -1;
    pesos[s] = 0;
    q.push(make_pair(0, s));
    
    while(!q.empty())
    {
        atual = q.top();
        q.pop();
        
        if(atual.second == e)
        {
            retorno = pesos[atual.second];
            break;
        }
        soma = pesos[atual.second];
        
        for(vector<pair<int, int> >::iterator i = (*a)[atual.second].begin(); i != (*a)[atual.second].end(); i++)
        {
            if(pesos[i->second] == -1) q.push(make_pair(soma+(i->first), i->second));
            
            if(((pesos[i->second] > soma+(i->first)) && (pesos[i->second] != 0)) || pesos[i->second] == -1)
                pesos[i->second] = soma+(i->first);
        }
    }
    free(pesos);
    return retorno;
}

int main()
{
    int n, m, start, end;
    int a, b, peso;
    int j;
    long long int result;
    vector<vector<pair<int, int> > > cidades;
    
    cin >> j;
    while(j-- > 0)
    {
        cin >> n >> m >> start >> end;
        
        cidades.clear();
        cidades.resize(n);
        
        for(int i = 0; i < m; i++)
        {
            cin >> a >> b >> peso;
            cidades[a-1].push_back(make_pair(peso, b-1));
            cidades[b-1].push_back(make_pair(peso, a-1));
        }
        
        result = dijkstra(&cidades, start-1, end-1);
        if(result == -1)
            cout << "NONE\n";
        else
            cout << result << endl;
    }
    return 0;
}
