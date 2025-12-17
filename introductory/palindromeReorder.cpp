#include <bits/stdc++.h>
using namespace std;

int main(){
  string input; cin >> input;
  vector<int> count(26, 0);
  for(int i = 0; i < input.size(); i++){
    count[input[i] - 'A'] += 1;
  }
  //for(int i = 0; i < 26; i++){
  //  cout << (char)('A' + i) << ' ' << count[i] << endl;
  //}
  int odd_count = 0;
  for(int i = 0; i < 26; i++){
    if(count[i] % 2 != 0){
      odd_count += 1;
    }
  }
  if(odd_count > 1){
    cout << "NO SOLUTION\n";
    return 0;
  }
  // create the half output
  string half_output = "";
  char center = 0;
  for(int i = 0; i < 26; i++){
    char current_char = 'A' + i;
    if(!(count[i] % 2 == 0)){
      center = current_char;
    }
    for(int j = 1; j < count[i]; j+=2){
      half_output += current_char;
    }
  }
  cout << half_output;
  if(center != 0) cout << center;

  for(int i = half_output.length() - 1; i >= 0; i--){
    cout << half_output[i];
  }
  cout << endl;
}
