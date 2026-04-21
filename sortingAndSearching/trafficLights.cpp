#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int x, n;
  scanf("%d %d", &x, &n);
  set<int> paths;
  paths.insert(0);
  paths.insert(x);
  multiset<int> ls;
  ls.insert(x);
  for(int i = 0; i < n; i++){
    int p; scanf("%d ", &p);
    auto pb = paths.upper_bound(p);
    int oe = *pb;
    pb--;
    int ob = (*pb);
    int ol = oe - ob;
    int nl1 = p - ob;
    int nl2 = oe - p;
    ls.erase(ls.find(ol));
    ls.insert(nl1);
    ls.insert(nl2);
    paths.insert(p);
    printf("%d\n", *(--ls.end()));
  }
}

