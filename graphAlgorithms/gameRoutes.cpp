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

const int MOD = 1e9+7;

int rec(int b, vi& nways, vvi& ptm){
  if(b == 0) return 1;
  if(nways[b] != -1) return nways[b];
  nways[b] = 0;
  for(int a : ptm[b]) nways[b] = (nways[b] + (rec(a, nways, ptm) % MOD)) % MOD;
  return nways[b];
}

int main(){
  int n, m;
  cin >> n >> m;
  vvi points_to_me(n);
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    points_to_me[b].push_back(a);
  }
  vi nways(n, -1);
  cout << rec(n-1, nways, points_to_me) % MOD << endl;
}
