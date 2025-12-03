#include <bits/stdc++.h>
using namespace std;

int main(void){
  // I don't even need to allocate a vector on this one;
  long long n; cin >> n;
  long long last, current;
  cin >> last;
  long long debt = 0;
  for(int i = 0; i < n - 1; i++){
    cin >> current;
    debt += max((long long)0, last - current);
    last = max(current, last);
  }
  cout << debt << endl;
}
