#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main(){
  int n; int x;
  cin >> n; cin >> x;
  int coins[n];
  int dp[x+1];
  dp[0] = 0;

  for(int i = 0; i < n; i++){
    cin >> coins[i];
  }
  sort(coins, coins+n);

  for(int i = 1; i <= x; i++){
    dp[i] = INF;
    for(int j = 0; j < n && coins[j] <= i; j++){
      dp[i] = min(dp[i], dp[i-coins[j]] + 1);
    }
  }

  if(dp[x] == INF){
    dp[x] = -1;
  }
  cout << dp[x] <<endl;
}

