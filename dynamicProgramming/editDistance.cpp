#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main(){
  string x, y;
  cin >> x >> y;
  int lx = x.length();
  int ly = y.length();
  vvi dp(lx + 1, vi(ly + 1));

  for(int i = 0; i <= lx; i++){
    for(int j = 0; j <= ly; j++){
      if(i == 0 || j == 0) dp[i][j] = max(i, j);
      else{
        dp[i][j] = min(
          min(dp[i-1][j] + 1, dp[i][j-1] + 1),
          dp[i-1][j-1] + (x[i-1] == y[j-1] ? 0 : 1));
      }
    }
  }
  cout << dp[lx][ly] << endl;
}
