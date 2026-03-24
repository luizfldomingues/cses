#include <bits/stdc++.h>
using namespace std;

void pbin(int n, int size){
  int i = size;
  while(i){
    cout << !((n & (1 << (i - 1))) == 0);
    i--;
  }
  cout << endl;
  return;
}

void rec(int answer, int n, int i, int dir){
  answer = answer ^ (dir << (n - i));
  if(i == n){
    pbin(answer, n);
    return;
  }
  rec(answer, n, i + 1, 0 ^ dir);
  rec(answer, n, i + 1, 1 ^ dir);
}

int main(){
  int n; cin >> n;
  rec(0, n, 0, 0);
}
