#include <bits/stdc++.h>
using namespace std;

typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const vpii directions = {
{0, 1},
{1, 0},
{1, 1},
{-1, -1},
{-1, 1},
{1, -1},
{0, -1},
{-1, 0},
};
 
vvc place_queen(vvc board, int a, int b){
  for(pii dir: directions){
    for(int m = 1;; m++){
      int i = a + m * dir.first;
      int j = b + m * dir.second;
      if(i < 0 || j < 0 || i >= 8 || j >= 8) break;
      board[i][j] = '*';
    }
  }
  return board;
}

int rec(vvc board, int c, int area_considered){
  if(c == 8) return 1;
  int total = 0;
  for(int i = area_considered; i < 64; i++){
    if(board[i/8][i%8] == '.'){
      total += rec(place_queen(board, i/8, i%8), c+1, i+1);
    }
  }
  return total;
}

int main(){
  vvc board(8, vc(8));
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++) cin >> board[i][j];
  }
  int answ = rec(board, 0, 0);
  cout << answ << endl;
}
