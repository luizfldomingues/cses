#include <bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef array<int, 5> v5;
#define f first
#define s second
const int INF = 1e9;

const vpii dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
const vc dir_names = {'U', 'L', 'R', 'D'};

bool is_valid(int i, int j, int n, int m){
  if(i < 0 || j < 0 || i >= n || j >= m) return false;
  return true;
}

int main(){
  int n, m; cin >> n >> m;
  vvc grid(n, vc(m));
  queue<pair<int, pii>> tvm;
  queue<v5> tvp;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> grid[i][j];
      if(grid[i][j] == 'M') tvm.push({0, {i, j}});
      else if(grid[i][j] == 'A') tvp.push({0, i, j, i, j});
    }
  }
  vvi dis_mons(n, vi(m, -1));
  vvi vis(n, vi(m, 0));
  // bfs for monster distances
  while(!tvm.empty()){
    auto [d, pos] = tvm.front();
    auto [i, j] = pos;
    tvm.pop();
    if(vis[i][j]) continue;
    vis[i][j] = 1;
    if(grid[i][j] == '#') continue;
    dis_mons[i][j] = d;
    for(auto [x, y] : dirs){
      int i1 = i + x;
      int j1 = j + y;
      if(!is_valid(i1, j1, n, m)) continue;
      if(vis[i1][j1]) continue;
      tvm.push({d + 1, {i1, j1}});
    }
  }
  for(int i = 0; i < n; i++){
    for(int j =0; j < m; j++) vis[i][j] = 0;
  }
  vvpii who_visited(n, vpii(m, {-1, -1}));
  vvi vis_player(n, vi(m, -1));
  bool has_answ = false;
  int ia, ja;
  // bfs for person
  while(!tvp.empty()){
    auto [d, i, j, i0, j0] = tvp.front();
    tvp.pop();
    if(vis_player[i][j] != -1) continue;
    if(grid[i][j] == '#') continue;
    if(dis_mons[i][j] <= d && dis_mons[i][j] != -1) continue;
    vis_player[i][j] = d;
    who_visited[i][j] = {i0, j0};
    dis_mons[i][j] = d;
    for(auto [x, y] : dirs){
      int i1 = i + x;
      int j1 = j + y;
      if(!is_valid(i1, j1, n, m)) continue;
      if(vis_player[i1][j1] != -1) continue;
      tvp.push({d + 1, i1, j1, i, j});
    }
    if(i == 0 || i == n - 1 || j == 0 || j == m - 1){
      has_answ = true;
      ia = i; ja = j; break;
    }
  }
  if(!has_answ){
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  cout << vis_player[ia][ja] << endl;
  vc answ;
  while(vis_player[ia][ja] != 0){
    auto [i, j] = who_visited[ia][ja];
    for(int k = 0; k < 4; k++){
      auto [x, y] = dirs[k];
      if(x + i == ia && y + j == ja){
        answ.push_back(dir_names[k]);
        continue;
      }
    }
    ia = i; ja = j;
  }
  for(int i = answ.size() -1; i >= 0; i--) cout << answ[i];
  cout << endl;
}
