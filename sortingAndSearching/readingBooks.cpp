#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef vector<int> vi;

int32_t main(){
  int n; cin >> n;
  vi books(n);
  for(int i = 0; i < n; i++) scanf("%lld", &books[i]);
  int s = 0;
  int g = 0;
  for(int i = 0; i < n; i++){
    s += books[i];
    g = max(books[i], g);
  }
  printf("%lld\n", max(2*g, s));
}
