#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main(){
  int n; cin >> n;
  vector<pii> movies;
  for(int i = 0; i < n; i++){
    pii movie;
    cin >> movie.second >> movie.first;
    movies.push_back(movie);
  }
  sort(movies.begin(), movies.end());
  int next_free = 0;
  int count = 0;
  for(int i = 0; i < n; i++){
    if(movies[i].second >= next_free){
      next_free = movies[i].first;
      count++;
    }
  }
  cout << count << endl;
}
