#include <bits/stdc++.h>
using namespace std;

typedef long long intl;

int main(){
  intl n; cin >> n;
  vector<intl> apples;
  intl buff;
  for(intl i = 0; i < n; i++){
    cin >> buff;
    apples.push_back(buff);
  }
  intl mindiff = 1000000001;
  intl a; intl b;
  for(intl i = 0; i < 1 << n; i++){
    a = 0; b = 0;
    for(intl j = 0; j < n; j++){
      if((i >> j) & 1){
        a += apples[j];
      } else{
        b += apples[j];
      }
    }
    mindiff = min(mindiff, a > b ? a - b : b - a);
  }
  cout << mindiff << endl;
}



