#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

bool cmpgr(vi a, vi b){
  return a[0] < b[0] ? true : (a[0] == b[0] ? a[1] > b[1] : false);
}

int main(){
  int n; cin >> n;
  vvi ranges(n, vi(3));
  for(int i = 0; i < n; i++){
    scanf("%d %d", &ranges[i][0], &ranges[i][1]);
    ranges[i][2] = i;
  }
  sort(ranges.begin(), ranges.end(), cmpgr);
  vi isContained(n, 0);
  vi contains(n, 0);

  vi br = ranges[0];
  for(int i = 1; i < n; i++){
    vi cr = ranges[i];
    if(br[1] >= cr[1]){
      isContained[cr[2]] = 1;
    } else{
      br = cr;
    }
  }

  br = ranges[n-1];
  for(int i = n - 2; i >= 0; i--){
    vi cr = ranges[i];
    if(br[1] <= cr[1]) contains[cr[2]] = 1;
    else br = cr;
  }

  for(int i = 0; i < n; i++){
    printf("%d ", contains[i]);
  }
  printf("\n");
  for(int i = 0; i < n; i++){
    printf("%d ", isContained[i]);
  }
  printf("\n");
}

