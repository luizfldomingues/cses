#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main(){
  int n, m; cin >> n >> m;
  int a[n], b[m];
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < m; i++) cin >> b[i];

  int dp[n+1][m+1];

  pii case_used[n+1][m+1];

  for(int i = n; i >= 0; i--){
    for(int j = m; j >= 0; j--){
      if(i == n || j == m){
        dp[i][j] = 0;
        case_used[i][j] = {-1, -1};
      } 
      else if(a[i] == b[j]){
        dp[i][j] = dp[i+1][j+1] + 1;
        case_used[i][j] = {i, j};
      } else{
        if(dp[i+1][j] > dp[i][j+1]){
          dp[i][j] = dp[i+1][j]; 
          case_used[i][j] = case_used[i+1][j];
        } else{
          dp[i][j] = dp[i][j+1];
          case_used[i][j] = case_used[i][j+1];
        }
      }
    }
  }

  cout << dp[0][0] << endl;

  pii c = case_used[0][0];
  while(c.first != -1 && c.second != -1){
    cout << a[c.first] << ' ';
    c = case_used[c.first+1][c.second+1];
  }
  cout << endl;

}
