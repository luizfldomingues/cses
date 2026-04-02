#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  map<int, int> x;
  int temp;
  for(int i = 0; i < n; i++){
    cin >> temp;
    x.insert({temp, i});
  }
  int rounds = 1;
  for(auto it = x.begin(); it != x.end(); it++){
    auto next = x.find((*it).first + 1);
    if(next == x.end()) break;
    if((*it).second > (*next).second) rounds++;
  }
  cout << rounds << '\n';
}
