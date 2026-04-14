#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  set<int> sums;
  sums.insert(0);
  queue<int> temp;
  for(int i = 0; i < n; i++){
    int coin; cin >> coin;
    for(auto it = sums.begin(); it != sums.end(); it++){
      temp.push(coin + *it);
    }
    while(temp.size() != 0){
      sums.insert(temp.front());
      temp.pop();
    }
  }
  cout << sums.size() - 1 << endl;
  for(auto it = sums.begin(); it != sums.end(); it++){
    if(*it == 0) continue;
    cout << *it << ' ';
  }
  cout << endl;
}
