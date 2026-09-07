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

int rec(vvi& tree, int a, vi& answ){
  int c = 1;
  for(auto b : tree[a]){
    c += rec(tree, b, answ);
  }
  answ[a] = c - 1;
  return c;
}

int32_t main(){
  int n; cin >> n;
  vvi tree(n);
  for(int i = 1; i < n; i++){
    int j; cin >> j;
    tree[j-1].push_back(i);
  }
  vi answ(n);
  rec(tree, 0, answ);
  for(auto c : answ) cout << c << ' ';
  cout << endl;
}
