#include <bits/stdc++.h>
using namespace std;

int main(){
  int x, n; cin >> n >> x;
  int c[n];
  for(int i = 0; i < n; i++) cin >> c[i];
  sort(c, c + n);
  int i = 0, j = n - 1, count = 0;
  while(i <= j){
    if(i == j){
      count++;
      break;
    }
    if(c[i] + c[j] <= x){
      count++; i++; j--;
    } else{
      count++;
      j--;
    }
  }
  cout << count << endl;
}
