#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
  int n; cin >> n;
  if(n < 4 && n != 1){
    cout << "NO SOLUTION\n";
    return 0;
  }
  if(n == 1){
    cout << 1 << '\n';
    return 0;
  }
  string base = "2 4 1 3";
  for(int i = 5; i <= n; i += 2){
    cout << i << ' ';
  }
  cout << base;
  for(int i = 6; i <= n; i += 2){
    cout << ' ' << i;
  }
  cout << '\n';
}
