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

// Function to search an element into vector 
bool searchFunc(vector<int> &v , int targetValue){
    for(int index = 0; index < v.size(); index++){
      if(v[index] == targetValue){
        return 1;
      }
    }
  return 0;
}

int main() {
  vector<int> v;
  v.push_back(11);
  v.push_back(12);
  v.push_back(13);

  if(v.size() == 3){
    cout << "vector size is 3" << endl;
    v.pop_back();
  }

  int targetValue = 12;
  bool isPresentElement = searchFunc(v,targetValue);
  
  if(isPresentElement){
    // printing the result
    cout << "Element is found" << endl;
  } else {
    cout << "Element is not found" << endl;
  }
  
  return 0;
}