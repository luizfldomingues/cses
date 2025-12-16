#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  
  // Count the min of divisors 5 and 2
  // The algorithm has to be at max O(n);
  // The number of divisores five will always be smaller
  // Just count the number of 5 divisors


  // application of Legendre's formulas
  int acumulator = 0;
  while(n != 0){
    n /= 5;
    acumulator += n;
  }
  cout << acumulator << endl;
}


