class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int n = nums.size();
        int end = n - 1;
        int mid = start + (end - start);

        while(start <= end){
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] <= target){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
            mid = start + (end - start);
        }
        return start;
    }
};