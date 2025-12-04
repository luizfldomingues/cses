#include <bits/stdc++.h>
using namespace std;

// One enough condition is: the sum of all numbers must be pair (that is n or n+1 is a multiple of four)

void phalfsum(int n0, int n1, bool first){
  // Receives a range of numbers
  // We are sure there are a multiple of four elements
  int delta = (n1 - n0) + 1; 
    int gap;
    if(first) gap = delta / 4;
    else gap = 0;
  for(int i = 0; i < delta/4; i++){
    cout << n0 + i + gap << ' ';
    cout << n1 - (i + gap);
    if(i != delta/4 - 1) cout << ' ';
  }
  cout << endl;
}

bool is_sum_pair(int n){
  // Checks if the sum of the numbers from 1 to n is pair
  // The complete sum is n(n-1)/2
  // It is enough that n or n+1 is multiple of four
  return (n % 4 == 0 || (n + 1) % 4 == 0);
}

int main(){
  int n; cin >> n;
  if(!is_sum_pair(n)){
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  if(n % 2 == 0){
    cout << n/2 << endl;
    phalfsum(1, n, true);
    cout << n/2 << endl;
    phalfsum(1, n, false);
  }
  else{
    cout << (n+1) / 2 << endl;
    cout << "1 2 ";
    phalfsum(4, n, true);
    cout << (n+1) / 2 - 1 << endl;
    cout << "3 ";
    phalfsum(4, n, false);
  }
}

