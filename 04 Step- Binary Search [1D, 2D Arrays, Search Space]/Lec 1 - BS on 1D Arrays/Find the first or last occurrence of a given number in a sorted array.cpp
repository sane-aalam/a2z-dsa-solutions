// # Binary seach (Simple)
// # remove one half on the basic of problem statement 

class Solution {
private:
    int FirstPositoin(vector<int> & nums, int target){
        int start = 0;
        int end = nums.size() - 1;
        // to fix the overflow error conditon
        int mid = start + (end-start)/2;

        int FirstIndex = -1;
        while(start <= end){
            if(nums[mid] == target){
                 // continue the seach left side to search last element into sorted array 
                 // binary search (super)!
                FirstIndex = mid;
                end = mid - 1;
            }else if(nums[mid] < target){
                start = mid + 1;
            }else{
                end = mid -1;
            }
            mid = start + (end-start)/2;
        }
        return FirstIndex;
    }
    int LastPosition(vector<int> & nums, int target){
        int start = 0;
        int end = nums.size() - 1;
        // to fix the overflow error conditon
        int mid = start + (end-start)/2;

        int lastIndex = -1;
        while(start <= end){
            if(nums[mid] == target){
                lastIndex = mid;
                start = mid + 1;
                // continue the search right side to search last element into sorted array 
            }else if(nums[mid] < target){
                start = mid + 1;
            }else{
                end = mid -1;
            }
             mid = start + (end-start)/2;
        }
        return lastIndex;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {

         if(nums.size() == 0){
            return {-1,-1};
         }
         int first_position = FirstPositoin(nums,target);
         int last_position = LastPosition(nums,target);

         return {first_position,last_position};
    }
};