#include <bits/stdc++.h>
using namespace std;

int bs(vector<pair<int,int>>& vec, int a, int b, int value){
  if(a < b){
    int mid = a + (b - a) / 2;
    if(vec[mid].first < value) return bs(vec, mid + 1, b, value);
    return bs(vec, a, mid, value);
  }
  if(a == b){
    if(vec[a].first == value) return a;
  }
  return -1;
}

int main(){
  int n, x; cin >> n >> x;
  vector<pair<int,int>> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i].first;
    a[i].second = i+1;
  }
  sort(a.begin(), a.end());
  for(int i = 1; i < n; i++){
    int diff = x - a[i].first;
    if(diff <= 0) continue;
    if(diff < x){
      int search_result = bs(a, 0, i-1, diff);
      if(search_result != -1){
        cout << a[search_result].second << ' ' << a[i].second << endl;
        return 0;
      }
    }
  }
  cout << "IMPOSSIBLE\n";
}
