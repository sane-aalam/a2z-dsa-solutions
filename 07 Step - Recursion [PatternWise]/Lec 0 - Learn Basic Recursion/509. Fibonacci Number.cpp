
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
   int helper(int n){
        // base case
        if(n <= 1){
            return n;
        }
        int firstLargestElement = helper(n-1);
        int secondLargestElement = helper(n-2);
        int sum = firstLargestElement + secondLargestElement;
        return sum;
   }
public:
    int fib(int n) {
        return helper(n);
    }
};