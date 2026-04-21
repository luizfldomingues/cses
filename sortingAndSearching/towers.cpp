#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  multiset<int> t;
  for(int i = 0; i < n; i++){
    int b; cin >> b;
    auto ub = t.upper_bound(b);
    if(ub != t.end()) t.erase(ub);
    t.insert(b);
  }
  cout << t.size() << endl;
}
