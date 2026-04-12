#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef vector<int> vi;
typedef vector<vi> vvi;

const int MOD = 1e9+7;

int32_t main(){
  int t; cin >> t; 
  vector<int> ts(t, 0);
  for(int i = 0; i < t; i++) cin >> ts[i];
  int n = *max_element(ts.begin(), ts.end());
  vvi dp(2, vi(n, 0));
  dp[0][0] = 1;
  dp[1][0] = 1;
  for(int i = 1; i < n; i++){
    dp[0][i] = ((4 * dp[0][i-1]) % MOD + dp[1][i-1]) % MOD;
    dp[1][i] = ((2 * dp[1][i-1]) % MOD + dp[0][i-1]) % MOD;
  }
  for(int i : ts) cout << ((dp[0][i-1] + dp[1][i-1]) % MOD) << endl;
}
