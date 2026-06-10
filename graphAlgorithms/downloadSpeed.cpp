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
typedef vector<vv3> vvv3;
#define f first
#define s second
const int INF = 1e12;

int dfs(vvi& rg, vi& vis, int thrs, int a, int min_c, int n){
  vis[a] = 1;
  if(a == n-1) return min_c;
  for(auto b = 0; b < n; b++){
    if(vis[b] || b == a) continue;
    int c = rg[a][b];
    if(c <= thrs) continue;
    int sr = dfs(rg, vis, thrs, b, min(min_c, c), n);
    if(sr != 0){
      rg[a][b] -= sr;
      rg[b][a] += sr;
      return sr;
    }
  }
  return 0;
}

int32_t main(){
  int n, m; cin >> n >> m;
  int thrs = 0;
  vvi rg(n, vi(n, 0));
  for(int i = 0; i < m; i++){
    int a, b, c; cin >> a >> b >> c;
    a--; b--;
    if(a == n-1 || b == 0) continue;
    rg[a][b] += c;
    thrs += c;
  }
  vi vis(n);
  while(true){
    for(int i = 0; i < n; i++) vis[i] = 0;
    int res = dfs(rg, vis, thrs, 0, INF, n);
    if(res == 0){
      if(thrs == 0) break;
      thrs /= 2;
    }
  }
  int answ = 0;
  for(int i = 0; i < n; i++){
    answ += rg[i][0];
  }
  cout << answ << endl;
}

