class Solution {
  public:
    void sort012(vector<int>& nums) {
        // code here
        
       int n = nums.size();
       int low = 0, mid = 0, high = n-1;
     
        while(mid <= high) {
            
            if (nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
            
            else if (nums[mid] == 1) {
                mid++;
            }
            
            else if (nums[mid] == 2) {
                swap(nums[mid], nums[high]);
                high--;
            }
        }   
    }
};