#include <bits/stdc++.h>
#include <queue>
using namespace std;

#define int long long
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
#define PQ priority_queue
#define f first
#define s second

const int INF = 10e10;


int32_t main(){
  int n, m; cin >> n >> m;
  vvpii g(n);
  for(int i = 0; i < m; i++){
    int a, b, c; cin >> a >> b >> c;
    g[a-1].push_back({b-1, c});
  }
  PQ<pii> pq;
  pq.push({0, 0});
  vi visited(n, INF);
  while(!pq.empty()){
    auto [cd, cn] = pq.top();
    cd = -cd;
    pq.pop();
    if(visited[cn] != INF) continue;
    visited[cn] = cd;
    for(auto [b, d] : g[cn]){
      pq.push({-(d + cd), b});
    }
  }
  for(int i = 0; i < n; i++){
    cout << visited[i] << ' ';
  }
  cout << endl;
}
