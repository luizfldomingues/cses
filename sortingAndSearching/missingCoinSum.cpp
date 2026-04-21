#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
  int n; cin >> n;
  int c[n];
  for(int i = 0; i < n; i++) cin >> c[i];
  sort(c, c+n);
  int mcs = 0;
  for(int i = 0; i < n; i++){
    if(mcs >= c[i] - 1) mcs += c[i];
    else break;
  }
  cout << mcs + 1 << '\n';
}
