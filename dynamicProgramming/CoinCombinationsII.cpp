#include <bits/stdc++.h>
using namespace std;

const int bint = 1e9 + 7;
 
int main(){
  int n, x; cin >> n; cin >> x;
  int coins[n];
  for(int i = 0; i < n; i++){
    cin >> coins[i];
  }
vector<int> dp(x, 0);

  for(int c = 0; c < n; c++){
    for(int i = 0; i < x; i++){
      if(i+1 == coins[c]) dp[i] += 1;
      else if(i+1 - coins[c] > 0) dp[i] += dp[i-coins[c]];
      dp[i] %= bint;
    }
  }
  cout << dp[x-1] << endl;
}

 
