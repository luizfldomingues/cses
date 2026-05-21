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

int rec(int b, vvi& ptme, vi& md, vi& lv){
  if(b == 0) return 0;
  if(lv[b] != -1) return md[b];
  for(int p : ptme[b]){
    int d = rec(p, ptme, md, lv);
    if(d + 1 > md[b]){
      lv[b] = p;
      if(d != -1) md[b] = d + 1;
    }
  }
  return md[b];
}

int main(){
  //ios_base::sync_with_stdio(0);
  //cin.tie(0);
  int n, m; cin >> n >> m;
  vvi adj(n);
  vvi ptme(n);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    a--; b--;
    adj[a].push_back(b);
    ptme[b].push_back(a);
  }
  vi md(n, -1);
  vi lv(n, -1);
  int c = rec(n-1, ptme, md, lv);
  if(c == -1){
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  vi answ;
  int b = n-1;
  answ.push_back(b);
  while(b != 0){
    answ.push_back(lv[b]);
    b = lv[b];
  }
  cout << answ.size() << '\n';
  for(int i = answ.size() - 1; i >= 0; i--){
    cout << answ[i] + 1 << ' ';
  }
  cout << '\n';
  
}
