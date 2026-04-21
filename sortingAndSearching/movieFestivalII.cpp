#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

typedef pair<int, int> pii;
typedef vector<pii> vpii;

int main(){
  int n, k; cin >> n >> k;
  vpii movies(n);
  multiset<int, greater<int>> people;
  for(int i = 0; i < n; i++) cin >> movies[i].s >> movies[i].f;
  sort(movies.begin(), movies.end());
  for(int i = 0; i < k; i++) people.insert(-1);
  int total = 0;
  for(int i = 0; i < n; i++){
    pii m = movies[i];
    auto p = people.lower_bound(m.s);
    if(p == people.end()) continue;
    total++;
    people.erase(p);
    people.insert(m.f);
  }
  cout << total << endl;
}
