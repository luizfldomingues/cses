#include <bits/stdc++.h>
using namespace std;
 
#define int long long
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef array<int, 3> v3;
typedef vector<v3> vv3;
#define f first
#define s second
 
int bs(int a, int b, int uplim, vpii& dp){
  if(a == b) return dp[a].f;
  int h = (a + b + 1) / 2;
  if(dp[h].s < uplim) return bs(h, b, uplim, dp);
  return bs(a, h-1, uplim, dp);
}
 
int32_t main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n; cin >> n;
  vv3 projects(n);
  for(int i = 0; i < n; i++){
    int a, b, p;
    cin >> a >> b >> p;
    projects[i] = {b, p, a};
  }
  sort(projects.begin(), projects.end());
  vpii dp = {{0, 0}};
  for(int i = 0; i < n; i++){
    auto [b, p, a] = projects[i];
    int use = bs(0, dp.size() - 1, a, dp) + p;
    int notuse = dp[dp.size()-1].f;
    if(use > notuse) dp.push_back({use, b});
  }
  cout << dp[dp.size() - 1].f << endl;
}
