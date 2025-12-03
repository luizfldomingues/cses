#include <bits/stdc++.h>
using namespace std;

int main(void){
  int n; cin >> n;
  vector<int> given(n);
  for(int i = 0; i < n - 1; i++){
    int k; cin >> k;
    given[k - 1] = 1;
  }
  for(int i = 0; i < n; i++){
    if(!given[i]){
      cout << i + 1 << endl;
    }
  }
}
