#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<vector<int>, pii> pvii;

bool c_pvii(pvii a, pvii b){
  return (a.first.size() > b.first.size()) || (a.first.size() == b.first.size() && a.second.second < b.second.second);
}

int main(){
  int n; cin >> n;
  int m; cin >> m;
  vector<int> a(n);
  vector<int> b(m);
  int buff;
  for(int i = 0; i < n; i++){
    cin >> buff;
    a[i] = buff;
  }
  for(int i = 0; i < m; i++){
    cin >> buff;
    b[i] = buff;
  }

  vector<vector<pvii>> dp(n+1, vector<pvii>(m+1));

  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= m; j++){
      dp[i][j] = {{}, {0, -1}};
      if(i == 0 || j == 0) continue;
      int new_digit = b[j-1];
      vector<pvii> options = {dp[i-1][j], dp[i][j-1]};
      sort(options.begin(), options.end(), c_pvii);

      // Case we include the new_digit in an already solved case
      int optionsNconsider = (options[0].first.size() < options[1].first.size()) ? 1 : 2;
      for(int optionN = 0;
      optionN < optionsNconsider && dp[i][j].first.size() == 0;
      optionN++){
        pvii option = options[optionN];
        if(j <= option.second.second) continue;
        for(int k = option.second.first + 1; k < i; k++){
          if(new_digit == a[k]){
            dp[i][j].first = option.first;
            dp[i][j].first.push_back(new_digit);
            dp[i][j].second = {k, j};
            break;
          }
        }
      }
      // Case we don't include the string and get the same answer for an already solved case
      if(dp[i][j].first.size() == 0 && options[0].first.size() > 0){
        dp[i][j].first = options[0].first;
        dp[i][j].second = options[0].second;
        continue;
      }

      // case the best option is to create a new subsequence
      if(dp[i][j].first.size() == 0){
        for(int k = 0; k < i; k++){
          if(new_digit == a[k]){
            dp[i][j].first.push_back(new_digit);
            dp[i][j].second = {k, j};
            break;
          }
        }
      }
    }
  }

  cout << dp[n][m].first.size() << endl;
  for(int i = 0; i < dp[n][m].first.size(); i++){
    cout << dp[n][m].first[i] << ' ';
  }
  cout << endl;
}
