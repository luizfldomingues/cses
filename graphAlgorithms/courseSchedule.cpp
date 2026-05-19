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


void bfs(int a, vvi& adj, vi& vis, vi& order, vi& cuv){
  if(cuv[a]){
    cout << "IMPOSSIBLE\n";
    exit(0);
  }
  if(vis[a]) return;
  cuv[a] = 1;
  vis[a] = 1;
  for(int b : adj[a]){
    bfs(b, adj, vis, order, cuv);
  }
  order.push_back(a);
  cuv[a] = 0;
}

int main(){
  int n, m; cin >> n >> m;
  vvi adj(n);
  for(int i = 0; i < m; i++){
    int a, b; cin >> b >> a;
    adj[a-1].push_back(b-1);
  }
  vi vis(n, 0);
  vi cuv(n, 0);
  vi order;
  for(int i = 0; i < n; i++){
    if(vis[i]) continue;
    bfs(i, adj, vis, order, cuv);
  }
  for(int j = 0; j < order.size(); j++){
    cout << order[j] + 1 << ' ';
  }
  cout << endl;
}
