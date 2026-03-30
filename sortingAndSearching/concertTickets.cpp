#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m; cin >> n >> m;
  multiset<int, greater<int>> t;
  int ticket;
  for(int i = 0; i < n; i++){
    cin >> ticket;
    t.insert(ticket);
  };
  int c;
  for(int i = 0; i < m; i++){
    cin >> c;
    auto price_it = t.lower_bound(c);
    if(price_it == t.end()){
      cout << "-1\n";
      continue;
    }
    cout << *price_it << '\n';
    t.erase(price_it);
  };
}
