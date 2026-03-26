#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

const int X[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
const int Y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
typedef pair<int, int> pii;

int n;

queue<pii> squares;

void get_neighbors(pii ij, vector<vector<int>>& board){
  int d = board[ij.first][ij.second];
  for(int k = 0; k < 8; k++){
    int x = ij.first + X[k];
    int y = ij.second + Y[k];
    if(x < 0 || y < 0 || x >= n || y >= n) continue;
    if(board[x][y] <= d + 1) continue;
    squares.push({x, y});
    board[x][y] = d+1;
  }
}

int main(){
  cin >> n;
  vector<vector<int>> board(n, vector<int>(n, INF));
  board[0][0] = 0;
  squares.push({0, 0});
  while(squares.size() > 0){
    get_neighbors(squares.front(), board);
    squares.pop();
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << board[i][j] << ' ';
    }
    cout << endl;
  }
}

