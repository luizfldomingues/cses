#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
  int n; cin >> n;
  int i = 0;
  for(; n != 0; i++){
    int g = 0;
    string ns = to_string(n);
    for(int j = 0; j < ns.size(); j++){
      if(ns[j] - '0' > g) g = ns[j] - '0';
    }
    n -= g;
  }
  cout << i << endl;
}
