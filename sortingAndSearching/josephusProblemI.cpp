#include <bits/stdc++.h>
using namespace std;

typedef struct node{
  int id;
  struct node* next;
} node;

int main(){
  int n; cin >> n;
  node* first = NULL;
  node* last = NULL;
  for(int i = n; i > 0; i--){
    node* nd = (node*)malloc(sizeof(node));
    nd->next = first;
    nd->id = i;
    first = nd;
    if(i == n) last = first;
  }
  last->next = first;
  node* p = first;
  while(p != p->next){
    node* next = p->next;
    node* nnext = next->next;
    p->next = next->next;
    cout << next->id << ' ';
    free(next);
    p = nnext;
  }
  cout << p->id << endl;
  free(p);
}
