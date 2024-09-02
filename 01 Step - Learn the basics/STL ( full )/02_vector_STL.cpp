
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
  cout << "Start of code ->" << endl;
  
  // Example-1
  vector<int> vec;
  vec.push_back(1);
  vec.push_back(21);
  vec.push_back(131);
  vec.push_back(12121);

  cout << "size of vector" << vec.size() << endl;
  cout << "capacity of vector" << vec.capacity() << endl;
  cout << "max size of vector" << vec.max_size() << endl;
  cout << "maximum element of vector" << *max_element(vec.begin(), vec.end()) << endl;
  cout << "minimum element of vector" << *min_element(vec.begin(), vec.end()) << endl;

  // Example-2
  vector<int> v(5,14);
  // size of 5 = [14,14,14,14,14];
  // check all element are same or not
  bool check = equal(v.begin(), v.end(), v.begin());
  cout << check << endl;
  cout << endl;

  // Example-3 copy the entire vector
  vector<int> newVec = v;
  for(int i = 0; i< newVec.size(); i++){
    cout << newVec[i] << " ";
  }
  cout << endl;

  // Exmaple-4 creation of 2D vector
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
  cout << "End of code -> " << endl;
  return 0;
}
