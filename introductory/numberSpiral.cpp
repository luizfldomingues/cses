#include <bits/stdc++.h>
using namespace std;

int main(){
int n; cin >> n;
for(int i = 0; i < n; i++){
    long long x, y; cin >> y; cin >> x;
    long long w = max(x, y);
    long long dig = 1 + (w) * (w - 1);
    int factor;
    if(w % 2 != 0) factor = -1;
    else factor = 1;
    long long delta = max(abs(w - x), abs(w - y));
    if(x > y) factor *= -1;
    cout << dig + factor * delta << endl;
  }
}
