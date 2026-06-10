#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef vector<vi> vvi;
 
int32_t main(){
  int n; cin >> n;
  vi a(n);
  int s = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    s += a[i];
  } 
  vvi dpt(n, vi(n, 0));
  vvi dpj(n, vi(n, 0));
  for(int i = 0; i < n; i++){
    for(int j = i; j >= 0; j--){
      if(i == j){
        dpt[i][j] = a[i];
        dpj[i][j] = -a[i];
      } else{
        dpt[i][j] = max(dpj[i-1][j] + a[i], dpj[i][j+1] + a[j]);
        dpj[i][j] = min(dpt[i-1][j] - a[i], dpt[i][j+1] - a[j]);
      }
    }
  }
  cout << (s + dpt[n-1][0]) / 2 << endl;
}
