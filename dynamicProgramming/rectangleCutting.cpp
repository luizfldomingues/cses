#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int INF = 1e9;

int main(){
  int x[2], a, b;
  cin >> x[0] >> x[1];
  sort(x, x + 2);
  a = x[0]; 
  b = x[1];
  vvi dp(a, vi(b));
  for(int i = 0; i < a; i++){
    for(int j = 0; j < b; j++){
      if(i == j){
        dp[i][j] = 0;
        continue;
      }
      dp[i][j] = INF;
      for(int k = 0; k < i; k++)
        dp[i][j] = min(dp[i][j], dp[i-k-1][j] + dp[k][j] + 1);
      for(int k = 0; k < j; k++)
        dp[i][j] = min(dp[i][j], dp[i][j-k-1] + dp[i][k] + 1);
    }
  }
  cout << dp[a-1][b-1] << endl;
}
