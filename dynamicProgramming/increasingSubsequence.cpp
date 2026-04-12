#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n; cin >> n;
  vector<int> p; 
  int x;
  for(int i = 0; i < n; i++){
    cin >> x;
    auto ub = lower_bound(p.begin(), p.end(), x);
    if(ub == p.end()) p.push_back(x);
    else *ub = x;
  }
  cout << p.size() << endl;
}
