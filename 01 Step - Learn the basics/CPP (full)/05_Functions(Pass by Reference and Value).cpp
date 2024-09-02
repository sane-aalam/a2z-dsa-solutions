// Functions (Pass by Reference and Value)

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
// Pass by reference (orignal vector is changed)
void searchFunc(vector<int> &v , int targetValue){
    for(int index = 0; index < v.size(); index++){
      if(v[index] == targetValue){
        cout << "present" << endl;
      }
    }
  v.push_back(15);
  v.push_back(15);
  v.push_back(15);
  v.push_back(15);
  v.push_back(15);
}

// Pass by value (not orignal vector is changed)
void searchFunc(vector<int> v , int targetValue){
    for(int index = 0; index < v.size(); index++){
      if(v[index] == targetValue){
        cout << "present" << endl;
      }
    }
  v.push_back(15);
  v.push_back(15);
  v.push_back(15);
  v.push_back(15);
  v.push_back(15);
}

int main() {
  vector<int> v;
  v.push_back(11);
  v.push_back(12);
  v.push_back(13);

  int targetValue = 12;
  searchFunc(v,targetValue);

  if(v.size() == 3){
    cout << "vector size is 3" << endl;
  }
  
  return 0;
}