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


int main(){
  int n, m; cin >> n >> m;
  vvi g(n);
  vi colors(n, 0);
  queue<pii> tv;
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    g[a-1].push_back(b-1);
    g[b-1].push_back(a-1);
  }
  for(int i = 0; i < n; i++){
    if(colors[i] == 0) tv.push({i, 1});
    while(!tv.empty()){
      auto [a, c] = tv.front();
      int nc = c == 1 ? 2 : 1;
      tv.pop();
      colors[a] = c;
      for(int b : g[a]){
        if(colors[b] == 0){
          tv.push({b, nc});
        }
        if(colors[b] == c){
          cout << "IMPOSSIBLE\n";
          exit(0);
        }
      }
    }
  }
  for(int i = 0; i < n; i++) cout << colors[i] << ' ';
  cout << '\n';
}
