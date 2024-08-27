class Solution {
private:
    void logicOfReverse(vector<int> & arr, int start, int end){
        
         while(start<end){
           int temp = arr[start];
           arr[start] = arr[end];
           arr[end] = temp;
           start++;
           end--;
       }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        
        // revere the complete array
        // reverse the 0-k 
        // reverse the k-n 
        logicOfReverse(nums,0,n -1);
        logicOfReverse(nums,0,k-1);
        logicOfReverse(nums,k,n - 1);
    }
};