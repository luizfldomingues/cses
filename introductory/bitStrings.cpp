#include <bits/stdc++.h>
using namespace std;

//const long long m = 1000000007;
const long long m = 1e9 + 7;

long long mod(long long a){
  return a % m;
}

long long powMod(long long a, long long n){
  if(n == 0) return 1;
  if(n == 1) return a;
  if(n % 2 == 0){
    return powMod(mod(mod(a) * mod(a)), n/2);
  }
  return mod(mod(a) * powMod(a, n -1));
}

int main(void){
  int n; cin >> n;
  cout << powMod(2, n) << endl;
  return 0;
}


