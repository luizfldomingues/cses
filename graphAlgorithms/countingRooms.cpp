#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int n, m;

int bfs(vector<string>& in, vvi& v, int i, int j){
  if(i >= n || j >= m || i < 0 || j < 0) return 0;
  if(in[i][j] == '#' || v[i][j] == 1) return 0;
  v[i][j] = 1;
  bfs(in, v, i+1, j);
  bfs(in, v, i, j+1);
  bfs(in, v, i, j-1);
  bfs(in, v, i-1, j);
  return 1;
}

int main(){
  cin >> n >> m;
  vector<string> in(n);
  for(int i = 0; i < n; i++) cin >> in[i];
  vvi visited(n, vi(m, 0));
  int rooms = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      rooms += bfs(in, visited, i, j);
    }
  }
  cout << rooms << endl;
}
