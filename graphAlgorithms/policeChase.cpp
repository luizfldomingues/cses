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

int dfs(vvi& adj, vi& vis, int a){
  if(a == n-1) return 1;
  vis[a] = 1;
  for(int b = 0; b < n; b++){
    if(adj[a][b] == 0) continue;
    if(vis[b]) continue;
    if(dfs(adj, vis, b) == 1){
      adj[a][b]--;
      adj[b][a]++;
      return 1;
    }
  }
  return 0;
}

int main(){
  cin >> n >> m;
  vvi adj0(n, vi(n, 0));
  vvi adj(n, vi(n, 0));
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    a--; b--;
    if(a != n-1) adj[a][b] = 1;
    if(a != 0) adj[b][a] = 1;
    adj0[a][b] = 1;
    adj0[b][a] = 1;
  }
  vi vis(n, 0);
  while(dfs(adj, vis, 0)) 
    fill(vis.begin(), vis.end(), 0);

  vpii answ;
  for(int a = 0; a < n; a++){
    if(vis[a] == 0) continue;
    for(int b = 0; b < n; b++){
      if(vis[b] || adj0[a][b] == 0) continue;
      answ.push_back({a+1, b+1});
    }
  }
  printf("%d\n", (int)answ.size());
  for(int i = 0; i < answ.size(); i++)
      printf("%d %d\n", answ[i].f, answ[i].s);
}
