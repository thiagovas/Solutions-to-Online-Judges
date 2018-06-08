#include <bits/stdc++.h>
using namespace std;

#define ZERO 1500

double M[4000][4000];
double tmp[4000][4000];

void updateM() {
  for(int i = ZERO; i < ZERO+1001; i++)
    for(int j = 0; j < 4000; j++)
      M[i][j] = tmp[i][j];
}

int main() {
  int p, k, n;
  double L, R;
  
  cin >> p;
  while(p--) {
    cin >> k >> n >> L >> R;
    memset(M, 0, sizeof(M));
    memset(tmp, 0, sizeof(tmp));
    M[ZERO][ZERO] = 1;
    for(int hue = 0; hue < n; hue++) {
      for(int r = ZERO; r < ZERO+1001; r++) {
        for(int i = 1; i < r; i++)
          tmp[r][i] = (1.0-L-R)*M[r][i] + L*M[r][i+1] + R*M[r][i-1];
        tmp[r][r] = (1.0-L-R)*M[r][r] + R*M[r-1][r-1] + R*M[r][r-1];
      }
      updateM();
    }
    
    double resp = 0, hue = 0;
    for(int i = ZERO; i <= 2*ZERO; i++) {
      hue = 0;
      for(int j = 0; j < 4000; j++)
        hue += M[i][j];
      resp += hue*(i-ZERO);
    }
    cout << std::fixed << setprecision(4) << k << " " << resp << endl;
  }
  
  return 0;
}
