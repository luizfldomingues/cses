#include <bits/stdc++.h>
using namespace std;

// One enough condition is: the sum of all numbers must be pair (that is n or n-1 is a multiple of four)

int main(){
  int n; cin >> n;
  if((n <= 1 || !(n % 4 == 0 || (n-1) % 4 == 0)) && n != 3){
    cout << "NO" << endl;
    return 1;
  }
  cout << "YES" << endl;
  if(!(n % 2)){
    cout << n/2 << endl;
    for(int i = 1; i <= (n/2)/2; i++){
      cout << i;
      cout << n - i + 1;
      if(!(i == n/4)) cout << ' ';
    }
    cout << endl << n/2 << endl;
    for(int i = 1; i <= (n/2)/2; i++){
      cout << (n / 4) + i;
      cout << n - (n / 4) - i + 1;
      if(!(i == n/4)) cout << ' ';
    }
    cout << endl;
  } else{
    cout << (n - 3) / 2 + 2 << endl;
    cout << "1 2 ";
    for(int i = 0; i < (n - 3)/2; i++){
      cout << i + 4;
      if(!(i == (n - 3)/2 - 1)) cout << endl;
    }
    cout << endl;
    cout << (n - 3) / 2 + 1 << endl;
    cout << "3 ";
    for(int i = 0; i < (n - 3)/2; i++){
      cout << i + i + 4 + (n - 3)/ 2;
      if(!(i == (n - 3)/2 - 1)) cout << endl;
    }
    cout << endl;
  }
}


