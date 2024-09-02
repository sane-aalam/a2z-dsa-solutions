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


int main() {
  vector<int> v;
  v.push_back(11);
  v.push_back(12);
  v.push_back(13);
  v.push_back(14);
  v.push_back(15);

  // foor loop in CPP
  int targetValue = 13;
  for(int index = 0; index < v.size(); index++){
      if(v[index] == targetValue){
        cout << "element is found" << endl;
      }
  }

   // While-Loop in CPP
   int targetValue2 = 14;
   int startIndex = 0;
   while(startIndex < v.size()){
        if(v[startIndex] == targetValue2){
            cout << "element is found" << endl;
        }
        // startIndex = startIndex + 1;
        startIndex++;
   }
  
  return 0;
}