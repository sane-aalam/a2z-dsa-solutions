
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


  // Iterators in C++ STL 
  vector<int>::iterator it = vec.begin();
  cout << (*it) << endl;
  it++;

  // complex way to iterate over a vector
  for(it = vec.begin(); it != vec.end(); it++){
    cout << (*it) << endl;
  } 

  // clean way to iterate over a vector
  for(auto it : vec){
    cout << it << " ";
  }
  cout << endl;
  cout << "End of code -> " << endl;
  return 0;
}
