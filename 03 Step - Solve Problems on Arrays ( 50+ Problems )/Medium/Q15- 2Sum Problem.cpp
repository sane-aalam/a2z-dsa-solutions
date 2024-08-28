class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i<nums.size(); i++){
            for(int j = i+1; j<nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }
};

// two pointer + extra memory space [save indexes value]

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> container;
        
        for(int i = 0; i<nums.size(); i++){
            container.push_back({nums[i],i});
        }

        sort(container.begin(),container.end());

        int start = 0;
        int end = nums.size() - 1; 

        while(start <= end){
            // the two numbers such that they add up to target.
            int twosum = container[start].first + container[end].first;
            if(twosum == target){
                int firstIndex = container[start].second;
                int lastIndex = container[end].second;
                return {firstIndex,lastIndex};

            // two number sum value is smaller, increasing the start pointer 
            // decreasing the end pointer 
            }else if(twosum < target){
                start++;
            }else{
                end--;
            }
        }
        return {};
    }
};