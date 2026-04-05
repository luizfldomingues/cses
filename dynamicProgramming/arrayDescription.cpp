#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<bitset<100>> vb;

const int MOD = 1e9+7;

int32_t main(){
  int n, m; cin >> n >> m;
  vb grid(n);
  int x;
  for(int i = 0; i < n; i++){
    cin >> x;
    if(x==0) for(int j = 0; j < m; j++) grid[i][j] = 1;
    else grid[i][x-1] = 1;
  }
  int dp[n][m];
  for(int j = 0; j < m; j++) dp[0][j] = grid[0][j] ? 1 : 0;
  for(int i = 1; i < n; i++){
    for(int j = 0; j < m; j++) dp[i][j] = 0;
  }

  for(int i = 1; i < n; i++){
    for(int j = 0; j < m; j++){
      if(!grid[i][j]) continue;
      int dpij = 0;
      j > 0 ? dpij += dp[i-1][j-1] : 0;
      dpij += dp[i-1][j];
      j < m - 1 ? dpij += dp[i-1][j+1] : 0;
      dp[i][j] = dpij % MOD;
    }
  }
  int answ = 0;
  for(int i = 0; i < m; i++) answ += dp[n-1][i];
  cout << answ % MOD << endl;
}
