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
 
int start_of_cicle = -1;
 
// rv 1: a cicle has been found and is being tracked back
// rv 2: a cycle was found and tracked back (just return 2 and do nothing)
// rv 0: no cycle has been found
int bfs(int a, vvi& graph, vpii& visited, int p){
  if(visited[a].f == 0) visited[a] = {1, -1};
  for(int neigh : graph[a]){
    if(neigh == p) continue;
    if(visited[neigh].f != 0){
      cout << visited[a].f - visited[neigh].f + 2 << endl;
      cout << neigh + 1 << ' ';
      cout << a + 1 << ' ';
      start_of_cicle = neigh;
      return 1;
    }
    visited[neigh] = {visited[a].f+1, a};
    int rv = bfs(neigh, graph, visited, a);
    if(rv == 1){
      cout << a + 1 << ' ';
      if(a == start_of_cicle){
        return 2;
      }
      return 1;
    }
    if(rv == 2) return 2;
  }
  return 0;
}
 
int main(){
  int n, m;
  cin >> n >> m;
  vvi g(n);
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    g[a-1].push_back(b-1);
    g[b-1].push_back(a-1);
  }
  //{visited, by}
  vpii visited(n, {0, -1});
  for(int i = 0; i < n; i++){
    if(!visited[i].f){
      if(bfs(i, g, visited, -2) == 2){
        cout << endl;
        return 0;
      }
    }
  }
  cout << "IMPOSSIBLE\n";
}
