#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n, m, k; cin >> n >> m >> k;
  int aparts[m]; int people[n];
  for(int i = 0; i < n; i++){
      cin >> people[i];
  }
  sort(people, people+n);
  for(int i = 0; i < m; i++){
      cin >> aparts[i];
  }
  sort(aparts, aparts+m);
 
  int i = 0, j = 0;
  int t = 0;
  while(i < n && j < m){
    if(abs(people[i] - aparts[j]) <= k){
      i++; j++; t++;
    } else if(people[i] < aparts[j]){
      i++;
    } else{
      j++;
    }
  }
  cout << t << endl;
}
