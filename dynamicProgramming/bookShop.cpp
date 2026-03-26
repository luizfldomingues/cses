#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, x; cin >> n >> x;
  int pages[n], prices[n];
  for(int i = 0; i < n; i++) cin >> prices[i];
  for(int i = 0; i < n; i++) cin >> pages[i];
  int dp[x+1];
  int xp1 = x+1;
  for(int i = x; i != 0; --i) dp[i] = 0;
  for(int i = 0; i < n; i++){
    for(int j = x; j >= prices[i]; j--){
      dp[j] = max(dp[j], dp[j - prices[i]] + pages[i]);
    }
  }
  cout << dp[x] << endl;
}
