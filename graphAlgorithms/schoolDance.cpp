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

int n, m, k;

int bfs(vvi& adj, vi& vis, int a){
  if(a == n + m + 1) return 1;
  vis[a] = 1;
  for(int b = 0; b < n + m + 2; b++){
    if(vis[b]) continue;
    if(adj[a][b] == 0) continue;
    if(bfs(adj, vis, b)){
      adj[a][b]--;
      adj[b][a]++;
      return 1;
    }
  }
  return 0;
}

int main(){
  cin >> n >> m >> k;
  vvi adj(n + m + 2, vi(n + m + 2, 0));
  for(int i = 0; i < k; i++){
    int a, b; cin >> a >> b;
    b += n;
    adj[a][b] = 1;
  }
  for(int i = 1; i <= n; i++) adj[0][i] = 1;
  for(int i = 1; i <= m; i++) adj[n + i][n + m + 1] = 1;
  vi vis(n + m + 2);
  while(bfs(adj, vis, 0))
    fill(vis.begin(), vis.end(), 0);
  vpii pairs;
  for(int i = 1; i <= m; i++){
    for(int j = 1; j <= n; j++){
      if(adj[n + i][j]) pairs.push_back({j, i});
    }
  }
  cout << pairs.size() << endl;
  for(pii couple : pairs){
    cout << couple.f << ' ' << couple.s << endl;
  }
}
