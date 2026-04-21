#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void print_sol(vvi& visited, int i, int j){
  int d = visited[i][j];
  int n = visited.size();
  int m = visited[0].size();
  string answ = string(d, 'X');
  
  while(d > 0){
    int si = d - 1;
    d--;
    if(i > 0 && visited[i-1][j] == d){
      i--;
      answ[si] = 'D';
    } else if(i < (n - 1) && visited[i+1][j] == d){
      i++;
      answ[si] = 'U';
    } else if(j > 0 && visited[i][j-1] == d){
      j--;
      answ[si] = 'R';
    } else if(j < (m-1) && visited[i][j+1] == d){
      answ[si] = 'L';
      j++;
    }
  }
  cout << "YES\n";
  cout << answ.size() << endl;
  cout << answ << endl;
}
 
int main(){
  int n, m; cin >> n >> m;
  vector<string> grid(n);
  for(int i = 0; i < n; i++) cin >> grid[i];
  queue<pii> tv;
  queue<string> paths;
  vvi visited(n, vi(m, -1));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(grid[i][j] == 'A'){
        tv.push({i, j});
        paths.push("");
        visited[i][j] = 0;
        break;
      }
    }
    if(!tv.empty()) break;
  }
  while(!tv.empty()){
    pii c = tv.front();
    int i = c.first;
    int j = c.second;
    int d = visited[i][j];
    tv.pop();
    if(grid[i][j] == '#') continue;
    if(grid[i][j] == 'B'){
      print_sol(visited, i, j);
      return 0;
    }
    if(i > 0 && visited[i-1][j] == -1 && grid[i-1][j] != '#'){
      tv.push({i - 1, j});
      visited[i-1][j] = d+1;
    }
    if(j > 0 && visited[i][j-1] == -1 && grid[i][j-1] != '#'){
      tv.push({i, j - 1});
      visited[i][j-1] = d+1;
    }
    if(i < n - 1 && visited[i+1][j] == -1 && grid[i+1][j] != '#'){
      tv.push({i + 1, j});
      visited[i+1][j] = d+1;
    }
    if(j < m - 1 && visited[i][j+1] == -1 && grid[i][j+1] != '#'){
      tv.push({i, j + 1});
      visited[i][j+1] = d+1;
    }
  }
  cout << "NO\n";
}
