#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
#define f first
#define s second

int32_t main(){
  int n; cin >> n;
  vpii tasks(n);
  for(int i = 0; i < n; i++) cin >> tasks[i].f >> tasks[i].s;
  sort(tasks.begin(), tasks.end());
  int total = 0;
  int time = 0;
  for(auto [a, d] : tasks){
    time += a;
    total += d - time;
  }
  cout << total << endl;
}
