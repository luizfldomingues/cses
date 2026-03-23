#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;

long long rec(ll a, ll b){
  if(b == 0) return 1;
  if(b % 2 == 0){
    ll a_b2 = rec(a, b/2);
    return (a_b2 * a_b2) % mod;
  } else{
    return (a * rec(a, b - 1)) % mod;
  }
}

int main(){
  int n; cin >> n;
  int a, b;
  for(int i = 0; i < n; i++){
    cin >> a >> b;
    cout << rec(a, b) << endl;
  }
}
