#include <bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef array<int, 3> v3;
typedef vector<v3> vv3;
#define f first
#define s second

int find(int a, vi& link){
  if(a == link[a]) return a;
  return link[a] = find(link[a], link);
}

bool same(int a, int b, vi& link){
  return find(a, link) == find(b, link);
}

void unite(int a, int b, vi& link, vi& size){
  a = find(a, link);
  b = find(b, link);
  if(size[b] > size[a]) swap(a, b);
  link[b] = a;
  size[a] += size[b];
}

int main(){
  int n, m; 
  cin >> n >> m;
  vv3 adj;
  for(int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    adj.push_back({c, a, b});
  }
  vi link(n);
  vi size(n);
  for(int i = 0; i < n; i++){
    link[i] = i;
    size[i] = 1;
  }
  ll total = 0;
  sort(adj.begin(), adj.end());
  for(auto [c, a, b] : adj){
    if(same(a, b, link)) continue;
    total += c;
    unite(a, b, link, size);
  }
  if(size[find(0, link)] != n){
    printf("IMPOSSIBLE\n");
    return 0;
  }
  printf("%lld\n", total);
}
