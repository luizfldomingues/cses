#include <stdio.h>

int main(){
  int n, x; scanf("%d %d", &n, &x);
  int pages[n], prices[n];
  for(int i = 0; i < n; i++) scanf("%d", prices+i);
  for(int i = 0; i < n; i++) scanf("%d", pages+i);
  int dp[x+1];
  for(int i = x; i != -1; --i) dp[i] = 0;
  for(int i = 0; i < n; i++){
    int price = prices[i];
    int page = pages[i];
    for(int j = x; j >= price; j--){
      int buy = dp[j - price] + page;
      dp[j] = dp[j] > buy ? dp[j] : buy;
    }
  }
  printf("%d\n", dp[x]);
}
