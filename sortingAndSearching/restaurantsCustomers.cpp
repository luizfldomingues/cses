#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int main(){
  int n; cin >> n;
  vector<pii> logs;
  for(int i = 0; i < n; i++){
    int time;
    cin >> time;
    logs.push_back({time, 1});
    cin >> time;
    logs.push_back({time, -1});
  }
  sort(logs.begin(), logs.end());
  int current = 0, record = 0;
  for(int i = 0; i < logs.size(); i++){
    current += logs[i].second;
    record = max(record, current);
  }
  cout << record << endl;
}
