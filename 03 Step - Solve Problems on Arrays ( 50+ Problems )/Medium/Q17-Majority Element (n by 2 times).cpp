// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times.
// You may assume that the majority element always exists in the array.

// Bruthforce Appraoch
// HashMap Approach
// More's Voting Algorithm 

// #1 native solution 
// 1681 ms
// Beats - 5.19%
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            int count = 0;
            int current_element = nums[i];
            for(int j = 0; j<n; j++){
                if(current_element == nums[j]){
                    count ++;
                }
            }

            if(count > n/2){
               return nums[i];
            }
        }
        return -1
    }
};

// HashMap solution 
// extra space complexity used here 

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> HashMap;
        int n = nums.size(); 
        for(int i = 0; i<n; i++){
            HashMap[nums[i]]++;
        }

        // Into HashMap [3 element, 4 times aaya hai]
        // it.first store array element
        // it.second store element freqency(number of times present into the array)
        for(auto it : HashMap){
            if(it.second > n/2){
                return it.first;
            }
        }

        return -1;
    }
};

// Optimal Approach: Moore’s Voting Algorithm:

 int majorityElement(vector<int>& nums) {
      int candidate = 0;
      int NumberOfmajorityElement = 0;

      for(int i = 0; i<nums.size(); i++){
            int candiate = 
      }      
 }