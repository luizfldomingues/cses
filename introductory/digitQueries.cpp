#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mypow(int a, int b){
  if(b == 0) return 1;
  if(b % 2 == 1) return a * mypow(a, b-1);
  ll a_b2 = mypow(a, b/2);
  return a_b2 * a_b2;
}

int32_t main(){
  int q; cin >> q;
  for(int t_case = 0; t_case < q; t_case++){
    ll k; cin >> k;
    ll min_v = 1, max_v = 9, digit_count = 1, t_digits = 0;
    while(t_digits + (max_v - min_v + 1) * digit_count < k){
      t_digits += (max_v - min_v + 1) * digit_count;
      max_v = 10 * max_v + 9;
      min_v *= 10;
      digit_count++;
    }
    ll parent_number = min_v + (k - t_digits - 1) / digit_count;
    ll digit = (parent_number / (mypow(10, (((digit_count) - ((k-t_digits-1)) % digit_count) - 1)))) % 10;
    cout << digit << endl;
  }
}
