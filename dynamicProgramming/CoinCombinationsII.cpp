#include <bits/stdc++.h>
using namespace std;

const int bint = 1e9 + 7;
 
int main(){
  int n, x; cin >> n; cin >> x;
  int coins[n];
  for(int i = 0; i < n; i++){
    cin >> coins[i];
  }
int dp[n][x];

  for(int i = 0; i < x; i++){
    for(int c = 0; c < n; c++){
      dp[c][i] = 0;
      if(i+1 == coins[c]) dp[c][i] += 1;
      if(c > 0) dp[c][i] += dp[c-1][i];
      if(i+1 - coins[c] > 0) dp[c][i] += dp[c][i-coins[c]];
      dp[c][i] %= bint;
    }
  }
  cout << dp[n-1][x-1] << endl;
}

 
