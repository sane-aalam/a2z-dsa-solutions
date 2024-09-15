class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
     int n = nums.size();
        
    // Edge case1 - when Only one element contain or Two element contain
    if(n == 1 or nums[0] > nums[1]){
        return 0;
    }

    // last element is greater to second last elements
    if(nums[n-1] > nums[n-2]){
        return n-1;
    }
        
        int start = 0;
        int end = nums.size() - 1;
        
        int mid = start + (end- start)/2;
        
        while(start < end){
            if(nums[mid] < nums[mid+1]){
                start = mid + 1;
            }else{
                end = mid;
            }
            mid = start + (end- start)/2;
        }
        return start;
    }
};