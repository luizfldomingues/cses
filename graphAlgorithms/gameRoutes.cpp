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
  for(int a = 0; a < n; a++){
    for(auto [d, b] : adj[a]){
      dist[b] = min(dist[b], dist[a] + d);
    }
  }
  int olda = dist[n-1];
  for(int a = 0; a < n; a++){
    for(auto [d, b] : adj[a]){
      dist[b] = min(dist[b], dist[a] + d);
    }
  }
  if(dist[n-1] != olda){
    printf("-1\n");
    return 0;
  }
  printf("%lld\n", -dist[n-1]);
}
