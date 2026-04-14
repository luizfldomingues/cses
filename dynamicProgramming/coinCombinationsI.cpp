#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int bint = 1e9 + 7;

int main(){
  int n, x; cin >> n; cin >> x;
  vector<int> coins(n, 0);
  for(int i = 0; i < n; i++){
    cin >> coins[i];
  }
  sort(coins.begin(), coins.end());

  vector<ll> dp(x+1, 0);

  for(int i = 0; i <= x; i++){
    for(int j = 0; j < n && coins[j] <= i; j++){
      if(coins[j] == i){
        dp[i] += 1;
        continue;
      }
      dp[i] += dp[i - coins[j]];
    }
    dp[i] %= bint;
  }
  cout << dp[x] << endl;
}
