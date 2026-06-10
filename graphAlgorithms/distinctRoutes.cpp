#include <bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
#define f first
#define s second

int n, m;

int dfs_fk(vvi& rg, vi& vis, int a){
  if(a == n-1) return 1;
  vis[a] = 1;
  for(int b = 0; b < n; b++){
    if(vis[b]) continue;
    if(rg[a][b] == 0) continue;
    if(dfs_fk(rg, vis, b)){
      rg[a][b]--;
      rg[b][a]++;
      return 1;
    }
  }
  return 0;
}

int dfs_fr(vvi& rg, vvi& adj, vvi& routes, vi& vis, int a){
  if(a == n-1){
    routes.push_back({a});
    return 1;
  }
  vis[a] = 1;
  int rs = routes.size();
  for(int b = 0; b < n; b++){
    if(vis[b]) continue;
    if(adj[a][b] - rg[a][b] > 0){
      if(dfs_fr(rg, adj, routes, vis, b)){
        rg[b][a]--;
        rg[a][b]++;
        routes[rs].push_back(a);
        vis[a] = 0;
        return 1;
      }
    }
  }
  return 0;
}

int main(){
  cin >> n >> m;
  vvi adj(n, vi(n, 0));
  vvi rg(n, vi(n, 0));
  for(int i =0 ;i < m; i++){
    int a, b; cin >> a >> b;
    a--; b--;
    adj[a][b] += 1;
    rg[a][b] += 1;
  }
  vi vis(n, 0);
  while(dfs_fk(rg, vis, 0)) 
    fill(vis.begin(), vis.end(), 0);
  fill(vis.begin(), vis.end(), 0);
  vvi routes;
  while(dfs_fr(rg, adj, routes, vis, 0))
    fill(vis.begin(), vis.end(), 0);
  cout << routes.size() << endl;
  for(vi route : routes){
    cout << route.size() << endl;
    for(int i = route.size() -1; i >= 0; i--){
      cout << route[i]+1 << ' ';
    }
    cout << endl;
  }
}
