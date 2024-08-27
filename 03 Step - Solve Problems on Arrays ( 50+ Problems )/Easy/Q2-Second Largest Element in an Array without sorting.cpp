
// Given an array arr, return the second largest distinct element from an array. 
// If the second largest element doesn't exist then return -1.

#include <vector>
using namespace std;

class Solution {
  public:
    // Function returns the second
    // largest elements
    int print2largest(vector<int> &arr) {
        // Code Here
        int largestElement = -1;
        int secondLargestElement = -1;

        // consider, What if arary contain only 1 Element
        // There is no second largest element present into the array 
        if(arr.size() == 1){
            return secondLargestElement;
        }

        for(int current_index = 0; current_index < arr.size(); current_index++){
        // if currentRank higher to student-1 Ranks
        // So you need to rearrange the ranks 
        // second student assign the value of firststudent rank 
	    // first student assign new value(High value)
            if(arr[current_index] > largestElement){
                secondLargestElement = largestElement;
                largestElement = arr[current_index];
            }else if(arr[current_index] < largestElement && 
                                        arr[current_index] > secondLargestElement){ 
        // what if you currentElement is smaller to the firstElement,
	    // and also greater to the nextElement,Then you can easy update
	    // the value of the secondElementMaximum
                secondLargestElement = arr[current_index];
            }
        }
        // return second maximum element into the array
        // we have already declare the condition, there is no second element 
        return secondLargestElement;
    }
};