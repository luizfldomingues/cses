#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main(){
  int n, m; cin >> n >> m;
  map<int, int> x;
  int temp;
  vector<int> pos(n, 0);
  for(int i = 0; i < n; i++){
    cin >> pos[i];
    x.insert({pos[i], i});
  }
  int rounds = 1;
  for(auto it = x.begin(); it != x.end(); it++){
    auto next = x.find((*it).first + 1);
    if(next == x.end()) break;
    if((*it).second > (*next).second) rounds++;
  }

  for(int i = 0; i < m; i++){
    int xa, xb; cin >> xa >> xb;
    xa--; xb--;
    int a = pos[xb];
    int b = pos[xa];
    pos[xa] = a; // xa is the new position
    pos[xb] = b;
    x.erase(a);
    x.erase(b);
    x.insert({a, xa});
    x.insert({b, xb});
    if(abs(a - b) == 1){
      if(a < b){
        if(xa < xb) rounds--;
        else rounds++;
      } else{
        if(xa < xb) rounds++;
        else rounds--;
      }
    }
    vector<vector<int>> changes {{a, xa,xb}, {b, xb, xa}}; // current value and new index
    for(vector<int> c : changes){
      if(c[0] > 1){
        int pred = x[c[0] - 1];
        if(xa != pred && xb != pred && ((pred < c[1]) != (pred < c[2]))) pred < c[1] ? rounds-- : rounds++;
      }
      if(c[0] < n){
        int suc = x[c[0] + 1];
        if(xa != suc && xb != suc && ((suc < c[1]) != (suc < c[2]))) suc > c[1] ? rounds-- : rounds++;
      }
    }
    cout << rounds << '\n';
  }
}
