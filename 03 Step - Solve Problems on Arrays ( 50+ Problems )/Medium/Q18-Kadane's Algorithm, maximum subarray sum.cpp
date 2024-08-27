
// Kadan's Algorithm
// arr[] = [-2,-3,4,-1,-2,1,5,-2]
// consider current_sum = -2 (arr[0])
// maximum_sum = INT_MIN;
// update the maximum_sum = which one greater current_sum, maximum_sum (-2)
// current_sum = current_sum + arr[1] = -2 + (-3)  = -5
// do really red to do this current sum (-5)
// you want to maximum_sum, no need (-5)
// more reduce the maximum_sum, you have to find maximum sum, 
// make sure, current sum is gonna to negative, 
// Restart the process,
//    if(current_sum < 0) current_sum = 0

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int maximum_sum = INT_MIN;
        int current_sum = 0;
        
        for(int index = 0; index < nums.size(); index++){
            current_sum = current_sum + nums[index];
            if(current_sum > maximum_sum){
                maximum_sum = current_sum;
            }
            
            if(current_sum < 0){
                current_sum = 0;
            }
        }
        return maximum_sum;
    }
};