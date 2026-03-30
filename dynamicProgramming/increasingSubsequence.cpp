#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n; cin >> n;
  int x[n];
  for(int i = 0; i < n; i++) cin >> x[i];
  int dp[n];
  for(int i = 0; i < n; i++){
    dp[i] = 1;
    for(int j = 0; j < i; j++){
      if(x[j] >= x[i]) continue;
      dp[i] = max(1 + dp[j], dp[i]);
    }
  }
  int answ = 0;
  for(int i = 0; i < n; i++){
    answ = max(answ, dp[i]);
  }
  cout << answ << endl;
}
