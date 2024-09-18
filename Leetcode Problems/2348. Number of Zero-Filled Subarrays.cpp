// Dry run of code
// nums = [1,3,0,0,2,0,0,4]
// when you reached nums[i] == 0, Then count = 1, result = result + count , (result = 1)
// when you reached nums[i] == 0, Then cout = 2, result = 1 + 2 = 3;
// Break the chain, restart the process, count = 0;
// For each zero, you can calculate the number of zero-filled subarrays that end on that index, 
// which is the number of consecutive zeros behind the current element + 1.

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
         long long result = 0;
         int count = 0;
         for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 0){
                count++;
            }else{
                count = 0;
            }
            result = result + count;
         }
         return result;
    }
};
