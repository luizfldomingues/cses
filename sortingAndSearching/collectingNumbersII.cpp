#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
 
int main(){
  int n, m; cin >> n >> m;
  vi x(n + 1);
  vi pos(n);
  for(int i = 0; i < n; i++){
    cin >> pos[i];
    x[pos[i]] = i;
  }
  int rounds = 1;
  for(int i = 1; i < n; i++) if(x[i] > x[i+1]) rounds++;
 
  for(int i = 0; i < m; i++){
    int xa, xb; cin >> xa >> xb;
    xa--; xb--;
    int a = pos[xb];
    int b = pos[xa];
    pos[xa] = a; // xa is the new position
    pos[xb] = b;
    x[a] = xa;
    x[b] = xb;
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
    for(int i = 0; i < 2; i++){
      int c0 = changes[i][0];
      int c1 = changes[i][1];
      int c2 = changes[i][2];
      if(c0 > 1){
        int pred = x[c0 - 1];
        if(pred != c2 && ((pred < c1) != (pred < c2))) pred < c1 ? rounds-- : rounds++;
      }
      if(c0 < n){
        int suc = x[c0 + 1];
        if(suc != c2 && ((suc < c1) != (suc < c2))) suc > c1 ? rounds-- : rounds++;
      }
    }
    cout << rounds << '\n';
  }
}
