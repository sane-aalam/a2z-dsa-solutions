class Solution {
public:
    int search(vector<int>& nums, int target) {

        int startIndex = 0;
        int endIndex = nums.size() - 1;
        int mid = startIndex + (endIndex - startIndex)/2;

        while(startIndex <= endIndex){
              if(nums[mid] == target){
                 return mid;
              }else if(nums[mid] < target){
                startIndex = mid + 1;
              }else{
                endIndex = mid - 1;
              }
            // we are updating the indexes (start,end)
            // we need to recalculate the again middle index point
            mid = startIndex + (endIndex - startIndex)/2;
        }
    // If target does'nt exist, then return its index. Otherwise, return -1.
        return -1;
    }
};


// recursive solution 
// Line 10: Char 12:
=================================================================
// ==23==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x502000001b94 at pc 0x55b349925d29 bp 0x7ffc8997a850 sp 0x7ffc8997a848
// mistake i am doing 
// passing end index = end - 1
// n - 1 pass
// fix the error of binary search [recursion]
// cool 

class Solution {
private:
    int binarysearch(int start, int end, vector<int> & nums, int target){
        if(start > end){
            return -1;
        }

        int mid = start + (end-start)/2;

        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] < target){
            // recursively search into right half 
            return binarysearch(mid+1,end,nums,target);
        }else{
            // recursively search into left half 
            return binarysearch(start,mid-1,nums,target);
        }
    }
public:
    int search(vector<int>& nums, int target) {
      int start = 0;
      int end = nums.size();
      return binarysearch(start,end,nums,target);   
    }
};