#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

const int mod = 1e9+7;

ll modpow(int a, int b){
  if(b == 0) return 1;
  if(b % 2 == 0){
    ll a_b2 = modpow(a, b/2);
    return (a_b2 * a_b2) % mod;
  }
  return (a * modpow(a, b-1)) % mod;
}

int main(){
  string s; cin >> s;
  vector<ll> count(26, 0);
  for(ll i = 0; i < s.length(); i++){
    count[s[i] - 'a']++;
  }
  ll num = 1;
  for(ll i = 0; i < s.length(); i++){
    num *= i + 1;
    num %= mod;
  }
  ll den = 1;
  for(ll i = 0; i < 26; i++){
    for(ll j = 0; j < count[i]; j++){
      den *= j + 1;
      den %= mod;
    }
  }
  cout << (((num % mod) * (modpow(den, mod - 2))) % mod) << endl;
}
