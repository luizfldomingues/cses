#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  vector<int> acc(n, 0);
  for(int j = 0; j < n; j++){
    acc[j] = 1 << (n - j - 1);
  }
  int twon = 1 << n;
  for(int i = 0; i < twon; i++){
    for(int j = 0; j < n; j++){
      int p = (1 << (n - j - 1));
      cout << (((p) + i & (p << 1)) && p);
    }
    cout << '\n';
  }

}
