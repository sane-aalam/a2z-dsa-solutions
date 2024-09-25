
#include <bits/stdc++.h>
using namespace std;

// When a function calls itself, until a special conditon is meet.

class Solution {
  private:
    void solve(int startIndex, int endIndex){
        if(startIndex > endIndex){
            return;
        }
        cout << "GFG" << " ";
        // increament for next index value
        startIndex++;
        solve(startIndex, endIndex);
    }
  public:
    void printGfg(int N) {
        // Code here
        int startIndex = 1;
        int endIndex = N;
        solve(startIndex,endIndex);
    }
};