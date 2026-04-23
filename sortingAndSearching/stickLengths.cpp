#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n; cin >> n;
  int p[n];
  ll accum = 0;
  for(int i = 0; i < n; i++){
    cin >> p[i];
    accum += p[i];
  }
  accum /= n;
  ll answ = 0;
  for(int i = 0; i < n; i++) answ += abs(p[i] - accum);
  cout << answ << endl;
}
