
#include <bits/stdc++.h>
using namespace std;

// STL on way
class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        reverse(arr.begin(),arr.end());
    }
};

// Recursion function
class Solution {
  private:
   void solve(vector<int> & arr, int startIndex, int endIndex){
       if(startIndex >= endIndex){
           return;
       }
       swap(arr[startIndex],arr[endIndex]);
       
       // indexes increment or decrement by 1 
       // for future calls 
       startIndex++;
       endIndex--;
       
       // call for baki ka array ke liye 
       solve(arr,startIndex, endIndex);
   }
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        int n = arr.size();
        int startIndex = 0;
        int endIndex = n -1;
        solve(arr,startIndex,endIndex);
    }
};