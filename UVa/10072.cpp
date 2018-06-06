#include <bits/stdc++.h>
using namespace std;

typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<int> VI;

double MinCostMatching(const VVD &cost, VI &Lmate, VI &Rmate) {
  int n = int(cost.size());

  // construct dual feasible solution
  VD u(n);
  VD v(n);
  for (int i = 0; i < n; i++) {
    u[i] = cost[i][0];
    for (int j = 1; j < n; j++) u[i] = min(u[i], cost[i][j]);
  }
  for (int j = 0; j < n; j++) {
    v[j] = cost[0][j] - u[0];
    for (int i = 1; i < n; i++) v[j] = min(v[j], cost[i][j] - u[i]);
  }

  // construct primal solution satisfying complementary slackness
  Lmate = VI(n, -1);
  Rmate = VI(n, -1);
  int mated = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (Rmate[j] != -1) continue;
      if (fabs(cost[i][j] - u[i] - v[j]) < 1e-10) {
        Lmate[i] = j;
        Rmate[j] = i;
        mated++;
        break;
      }
    }
  }

  VD dist(n);
  VI dad(n);
  VI seen(n);

  // repeat until primal solution is feasible
  while (mated < n) {

    // find an unmatched left node
    int s = 0;
    while (Lmate[s] != -1) s++;

    // initialize Dijkstra
    fill(dad.begin(), dad.end(), -1);
    fill(seen.begin(), seen.end(), 0);
    for (int k = 0; k < n; k++) 
      dist[k] = cost[s][k] - u[s] - v[k];

    int j = 0;
    while (true) {

      // find closest
      j = -1;
      for (int k = 0; k < n; k++) {
        if (seen[k]) continue;
        if (j == -1 || dist[k] < dist[j]) j = k;
      }
      seen[j] = 1;

      // termination condition
      if (Rmate[j] == -1) break;

      // relax neighbors
      const int i = Rmate[j];
      for (int k = 0; k < n; k++) {
        if (seen[k]) continue;
        const double new_dist = dist[j] + cost[i][k] - u[i] - v[k];
        if (dist[k] > new_dist) {
          dist[k] = new_dist;
          dad[k] = j;
        }
      }
    }

    // update dual variables
    for (int k = 0; k < n; k++) {
      if (k == j || !seen[k]) continue;
      const int i = Rmate[k];
      v[k] += dist[k] - dist[j];
      u[i] -= dist[k] - dist[j];
    }
    u[s] += dist[j];

    // augment along path
    while (dad[j] >= 0) {
      const int d = dad[j];
      Rmate[j] = Rmate[d];
      Lmate[Rmate[j]] = j;
      j = d;
    }
    Rmate[j] = s;
    Lmate[s] = j;

    mated++;
  }

  double value = 0;
  for (int i = 0; i < n; i++)
    value += cost[i][Lmate[i]];

  return value;
}



#define MAXN 200
int bt[MAXN], bl[MAXN], fl[MAXN];


int main()
{
  ios::sync_with_stdio(false);
  
  int n, btn, bln, arn, teste=1;
  
  while(true) {
    cin >> n;
    if(not cin) break;
    if(n == 0) break;
    if(teste != 1) cout << endl;
    cout << "Team #" << teste++ << endl;
    VVD cost(n, VD(n, 10));
    
    for(int i = 0; i < n; i++)
      cin >> bt[i] >> bl[i] >> fl[i];
    
    cin >> btn >> bln >> arn;
    for(int i = 0; i < btn; i++)
      for(int j = 0; j < n; j++)
        cost[i][j] = -round(0.8*bt[j] + 0.2*fl[j]);

    for(int i = btn; i < btn+bln; i++)
      for(int j = 0; j < n; j++)
        cost[i][j] = -round(0.1*bt[j] + 0.7*bl[j] + 0.2*fl[j]);
    
    for(int i = btn+bln; i < btn+bln+arn; i++)
      for(int j = 0; j < n; j++)
        cost[i][j] = -round(0.4*bt[j] + 0.4*bl[j] + 0.2*fl[j]);
    
    VI lmate, rmate;
    cout << "Maximum Effective Score = ";
    cout << -(MinCostMatching(cost, lmate, rmate)-10*(n-btn-bln-arn)) << endl;
    cout << "Batsmen : ";
    vector<int> vtmp;
    for(int i = 0; i < btn; i++)
      if(lmate[i] < n) vtmp.push_back(lmate[i]+1);
    sort(vtmp.begin(), vtmp.end());
    for(int i = 0; i < vtmp.size(); i++) {
      if(i != 0) cout << " ";
      cout << vtmp[i];
    }
    cout << endl;
    vtmp.clear();
    
    cout << "Bowlers : ";
    for(int i = btn; i < btn+bln; i++)
      if(lmate[i] < n) vtmp.push_back(lmate[i]+1);
    sort(vtmp.begin(), vtmp.end());
    for(int i = 0; i < vtmp.size(); i++) {
      if(i != 0) cout << " ";
      cout << vtmp[i];
    }
    cout << endl;
    vtmp.clear();
    
    cout << "All-rounders : ";
    for(int i = btn+bln; i < btn+bln+arn; i++)
      if(lmate[i] < n) vtmp.push_back(lmate[i]+1);
    sort(vtmp.begin(), vtmp.end());
    for(int i = 0; i < vtmp.size(); i++) {
      if(i != 0) cout << " ";
      cout << vtmp[i];
    }
    cout << endl;
  }

  return 0;
}
