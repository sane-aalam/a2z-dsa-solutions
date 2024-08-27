
// You have been given an array ‘a’ of ‘n’ non-negative integers.You have to check
//  whether the given array is sorted in the non-decreasing order or not.
// Your task is to return 1 if the given array is sorted. Else, return 0.
// Input: ‘n’ = 5, ‘a’ = [1, 2, 3, 4, 5]
// Output: 1

// TC - 0(n)
// Sc - 0(1)

#include <vector>
using namespace std;

int isSorted(int n, vector<int> a) {
    // Write your code here.
    int issortedArray = 0;

    for(int currentIndex = 0; currentIndex < a.size()-1; currentIndex++){
       if(a[currentIndex] <= a[currentIndex+1]){
          issortedArray = 1;
       // When break the chain- accessing order maintain rule 
       // Then array is not sorted 
       // return false
       }else if(a[currentIndex] > a[currentIndex +1]){
          issortedArray = 0;
          break;
       }
    }
    return issortedArray;
}
