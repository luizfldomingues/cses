#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
typedef vector<int> vi;

bool ver(int a, int t, vi& m){
  int total = 0;
  for(int machine : m) total += (a / machine);
  if(total >= t) return true;
  return false;
}

int bs(int a, int b, int t, vi& m){
  if(a == b) return a;
  int h = a + (b - a) / 2;
  if(ver(h, t, m)) return bs(a, h, t, m);
  return bs(h+1, b, t, m);
}

int32_t main(){
  int n, t; cin >> n >> t;
  vi m(n);
  for(int i = 0; i < n; i++) cin >> m[i];
  sort(m.begin(), m.end(), greater<int>());
  cout << bs(0, m[0] * t, t, m) << endl;
}
