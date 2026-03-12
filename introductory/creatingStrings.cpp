#include <bits/stdc++.h>
using namespace std;
// Interesting problem
// The number of permuations is n! divided by the product of factorial of repetition count


int rec(int k, string s, int a1, int a2, set<string>& permutations){
  if(a1 != a2 && s[a1] == s[a2]){
    return 0;
  }
  if(k != 0 && a1 != a2){
    s[a1] = s[a1] ^ s[a2];
    s[a2] = s[a1] ^ s[a2];
    s[a1] = s[a1] ^ s[a2];
  }

  if(k == s.length()){
    permutations.insert(s);
    return 1;
  }
  for(int i = k; i < s.length(); i++){
    rec(k+1, s, k, i, permutations);
  }
  return 0;
}

int main(){
  string input; cin >> input;

  vector<int> ccount(26, 0);
  for(int i = 0; i < input.size(); i++){
    ccount[input[i] - 'a']++;
  }

  set<string> permutations;

  rec(0, input, 0, 0, permutations);
  cout << permutations.size() << endl;
  for(auto i = permutations.begin(); i != permutations.end(); i++){
    cout << *i << endl;
  }
}
