

// maximum consecutive ones
// ? Algorithm
// take curr-consective variable,maxi-consecutive variable
// count curr-consective
// update with maximum count 
// make sure when you break the chain, re-start the current-consective ness

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int current_consecutive = 0;
        int maximum_consecutive = 0;

        for(int index = 0; index < nums.size(); index++){
            if(nums[index] == 1){
                current_consecutive++;
                maximum_consecutive = max(current_consecutive,maximum_consecutive);
            }
            // Break the chain of consecutive '1
            // restart the process
            else{
                current_consecutive = 0;
            }
        }
        return maximum_consecutive;
    }
};