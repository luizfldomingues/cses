#include <bits/stdc++.h>
#include <queue>
using namespace std;
 
typedef vector<int> vi;
typedef pair<int, int> pii;
 
typedef priority_queue<pii, vector<pii>, greater<pii>> pqpii;
 
int main(){
  int n; cin >> n;
  vector<vi> customers(n, vi(3));
  for(int i = 0; i < n; i++){
    cin >> customers[i][0];
    cin >> customers[i][1];
    customers[i][2] = i;
  }
  sort(customers.begin(), customers.end());
  pqpii rooms;
  rooms.push({0, 1});
  for(int i = 0; i < n; i++){
    if(rooms.top().first >= customers[i][0]){
      rooms.push({0, rooms.size() + 1});
    }
    int room = rooms.top().second;
    rooms.pop();
    rooms.push({customers[i][1], room});
    customers[i][0] = customers[i][2];
    customers[i][1] = room;
  }
  sort(customers.begin(), customers.end());
  cout << rooms.size() << endl; 
  for(int i = 0; i < n; i++){
    cout << customers[i][1] << ' ';
  }
  cout << endl;
}

