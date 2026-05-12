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
const int INF = 1e13;

int32_t main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vvi adj(n, vi(n, INF));
  for(int i = 0; i < m; i++){
    int a, b, c; cin >> a >> b >> c;
    a--; b--;
    adj[a][b] = min(c, adj[a][b]);
    adj[b][a] = min(c, adj[b][a]);
  }
  for(int i = 0; i < n; i++) adj[i][i] = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      for(int k = 0; k < n; k++)
        adj[j][k] = min(adj[j][k], adj[j][i] + adj[i][k]);
    }
  }

  while(q--){
    int a, b;
    cin >> a >> b;
    a--; b--;
    cout << (adj[a][b] == INF ? -1 : adj[a][b]) << '\n';
  }
}

