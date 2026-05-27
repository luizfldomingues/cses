#include <bits/stdc++.h>
using namespace std;
 
#define int long long
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
#define f first
#define s second
 
const int MOD = 1e9+7;
const int INF = 1e15;

int dfs(int a, int n, vvpii& adj, vi& nodes){
  if(a == n){
    nodes[a] = 2;
    return 1;
  };
  if(nodes[a] == 1) return 0;
  if(nodes[a] == 2) return 1;
  nodes[a] = 1;
  int has_reached_n = 0;
  for(auto [x, b] : adj[a]){
    if(dfs(b, n, adj, nodes) == 1) has_reached_n = 1;
  }
  if(has_reached_n == 1) nodes[a] = 2;
  return has_reached_n;
}

int32_t main(){
  int n, m;
  cin >> n >> m;
  vvpii adj(n);
  for(int i = 0; i < m; i++){
    int a, b, x;
    cin >> a >> b >> x;
    a--; b--;
    adj[a].push_back({-x, b});
  }
  vi dist(n,INF);
  dist[0] = 0;
  for(int i = 0; i < n; i++){
    for(int a = 0; a < n; a++){
      for(auto [d, b] : adj[a]){
        dist[b] = min(dist[b], dist[a] + d);
      }
    }
  }
  vi dist0(n);
  for(int i = 0; i < n; i++) dist0[i] = dist[i];
  for(int i = 0; i < n; i++){
    for(int a = 0; a < n; a++){
      for(auto [d, b] : adj[a]){
        dist[b] = min(dist[b], dist[a] + d);
      }
    }
  }
  vi path(n, 0);
  dfs(0, n-1, adj, path);

  for(int i = 0; i < n; i++) if(dist0[i] != dist[i] && path[i] == 2){
    printf("-1\n");
    return 0;
  }
  printf("%lld\n", -dist[n-1]);
}
