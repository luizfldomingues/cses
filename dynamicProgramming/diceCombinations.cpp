#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007;
typedef long long ll;

int main(){
  int n; cin >> n;
  vector<ll> dp(n + 1, 0);
  dp[0] = 1;
  dp[1] = 1;
  for(int i = 2; i <= n; i++){
    ll accum = 0;
    for(int j = 1; j <= 6 && j <= i; j++){
      accum += dp[i - j]; accum %= mod;
    }
    dp[i] = accum;
  }
  cout << dp[n] << endl;
}
