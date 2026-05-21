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


int lc = 1;

int dsu(int a, int b, vi& l, vi& size){
  if(a == b) return 0;
  if(a == l[a] && b == l[b]){
    l[b] = a;
    size[a] += size[b];
    lc = max(lc, size[a]);
    return 1;
  }
  l[a] = l[l[a]];
  l[b] = l[l[b]];
  return dsu(l[a], l[b], l, size);
}

int main(){
  int n, m; cin >> n >> m;
  vi leader(n);
  for(int i = 0; i < n; i++) leader[i] = i;
  vi size(n, 1);
  int total = n;
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    total -= dsu(a-1, b-1, leader, size);
    printf("%d %d\n", total, lc);
  }
}
