
#include <algorithm>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <typeinfo>
#include <vector>
using namespace std;

int main(){

  int n = 4;
  int m = 4;
  vector<vector<int>> grid (n,vector<int>(m,12));
  // will create (4,4) matrix with all element as 12

  // printing 2D vector using simple
  // Matrix tarversal [easy]
  for(int row = 0; row < n; row++){
    for(int col = 0; col < m; col++){
      cout << grid[row][col] << " ";
    }
  }

  cout << endl;
  return 0;
}
