

#include <bits/stdc++.h>
using namespace std;

class Solution{
    private:
    void solve(int currentNumber, int endNumber){
        if(currentNumber > endNumber){
            return;
        }
        
        cout << currentNumber << " ";
        currentNumber ++;
        solve(currentNumber,endNumber);
    }
    public:
    //Complete this function
    void printNos(int N)
    {
        //Your code here
        int startNumber = 1;
        solve(startNumber,N);
    }
};