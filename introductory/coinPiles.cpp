#include <bits/stdc++.h>
using namespace std;

int main(){
  int t; cin >> t;
  int a, b;
  for(int i = 0; i < t; i++){
    cin >> a;
    cin >> b;
    if(!((a + b) % 3 == 0)){
      cout << "NO\n";
      continue;
    }
    if(a < b){
      int temp = a;
      a = b;
      b = temp;
    }
    if(a > 2*b){
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
  }
}
