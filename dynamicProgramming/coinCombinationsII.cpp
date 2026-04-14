#include <bits/stdc++.h>
using namespace std;
 
const int bint = 1e9 + 7;
 
int main(){
  int n, x; cin >> n; cin >> x;
  vector<int> coins(n, 0);
  for(int i = 0; i < n; i++){
    cin >> coins[i];
  }
int dp[n][x+1];
 
  for(int c = 0; c < n; c++){
    for(int i = 0; i <= x; i++){
      dp[c][i] = 0;
      if(i == 0) continue;
      if(i == coins[c]) dp[c][i] += 1;
      if(c > 0) dp[c][i] += dp[c-1][i];
      if(i - coins[c] > 0) dp[c][i] += dp[c][i-coins[c]];
      dp[c][i] %= bint;
    }
  }
  cout << dp[n-1][x] << endl;
}

