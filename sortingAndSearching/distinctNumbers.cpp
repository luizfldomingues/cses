#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  vector<int> values;
  for(int i = 0; i < n; i++){
    int temp; cin >> temp;
    values.push_back(temp);
  }
  sort(values.begin(), values.end());
  int distinct = 1;
  int current = values[0];
  for(int i = 1; i < n; i++){
    if(values[i] != current){
      current = values[i];
      distinct += 1;
    }
  }
  cout << distinct << endl;
}

