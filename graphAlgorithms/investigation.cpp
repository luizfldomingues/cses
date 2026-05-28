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

int nways(int b, vvpii& ptm, vi& dis, vi& dpnways, vi& dpminc, vi& dpmaxc){
  if(dpnways[b] != -1) return dpnways[b];
  dpnways[b] = 0;
  for(auto [c, a] : ptm[b]){
    if(dis[a] + c > dis[b]) continue;
    dpnways[b] += nways(a, ptm, dis, dpnways, dpminc, dpmaxc) % MOD;
    dpnways[b] %= MOD;
    dpminc[b] = min(dpminc[b], dpminc[a] + 1);
    dpmaxc[b] = max(dpmaxc[b], dpmaxc[a] + 1);
  }
  return dpnways[b];
}

int32_t main(){
  int n, m;
  cin >> n >> m;
  vvpii adj(n);
  vvpii ptm(n);
  for(int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    adj[a].push_back({c, b});
    ptm[b].push_back({c, a});

  }
  priority_queue<pii> tv;
  tv.push({0, 0});
  vi dis(n, -1);
  while(!tv.empty()){
    auto [d, a] = tv.top();
    tv.pop();
    if(dis[a] != -1) continue;
    d = -d;
    dis[a] = d;
    for(auto [c, b] : adj[a]){
      tv.push({-(d + c), b});
    }
  }
  cout << dis[n-1] << ' ';
  vi dpnways(n, -1);
  dpnways[0] = 1;
  vi dpminc(n, INF);
  dpminc[0] = 0;
  vi dpmaxc(n, -1);
  dpmaxc[0] = 0;
  cout << nways(n-1, ptm, dis, dpnways, dpminc, dpmaxc) << ' ';
  cout << dpminc[n-1] << ' ';
  cout << dpmaxc[n-1] << endl;
}
