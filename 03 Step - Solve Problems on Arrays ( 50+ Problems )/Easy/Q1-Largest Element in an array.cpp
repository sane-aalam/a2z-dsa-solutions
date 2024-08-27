// Given an array, arr. The task is to find the largest element in it.
// Infosys Oracle Wipro Morgan Stanley
// Tc-0(N)
// Sc-0(1)
#include <vector>
using namespace std;

class Solution{
public:
    int largest(vector<int> &arr, int n)
    {
        int largestElement = arr[0];
        if(n == 1){
            return largestElement;
        }
        
        for(int currentIndex = 0; currentIndex < n; currentIndex++){
            if(arr[currentIndex] > largestElement){
                largestElement = arr[currentIndex];
            }
        }
        return largestElement;
    }
};