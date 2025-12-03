#include <bits/stdc++.h>
using namespace std;

int main(){
  int longest, streak; longest = streak = 1;
  char c, lastChar;
  lastChar = 'B';
  while(cin >> c){
    if(lastChar != c){
      streak = 1;
      lastChar = c;
      continue;
    }
    streak++;
    longest = max(longest, streak);
  }
  cout << longest << endl;
}
