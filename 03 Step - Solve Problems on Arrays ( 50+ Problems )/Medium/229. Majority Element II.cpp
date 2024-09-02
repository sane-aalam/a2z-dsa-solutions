
  // inorder to reduce the space complexity of the code
    // we can use "MORE VOTING ALGORITHM"
    // 1. declare the firstCandidate,With count = 1
    // 2. if you got same vote,Then incease the count
    // 3. if you not got same vote,Then decease the count 
    // 4. repeat the process 

    // more voting algorithm (extension version)
    // keep track two variable candidate1, candidate2, count1,count2
    // to make sure the edges case 

// 📌 Map solution [extra space compleixty used here]

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int,int> mp;
        for(auto num : nums){
            mp[num]++;
        }

        vector<int> result;
        for(auto it : mp){
            if(it.second > n/3){
                result.push_back(it.first);
            }
        }
        return result;
    }
};

// 📌 More-Voting Algorithm [extension version]
// Easy to understand [if you have solved MajorityElement problem-1]
// Majority Element II is a very interesting challenge. 💪🤩
// The HashMap Solution is an easy approach but Boyer-Moore Majority Voting approach is more interesting one🚀🤩
// I hope everyone has understood the explanation and the code.🙏😊

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

         int majorityElement1 = 0;
         int count1 = 0;

         int majorityElement2 = 0;
         int count2 = 0;

         for(int index = 0; index < nums.size(); index++){
           // assign new candidate using vote-1 
           // if next candidate is equal count++ otherwise count--
             if(count1 == 0 && majorityElement2 != nums[index]){
                count1 = 1;
                majorityElement1 = nums[index];
             }else if(count2 == 0 && majorityElement1 != nums[index]){
                count2 = 1;
                majorityElement2 = nums[index];
             }else if(majorityElement1 == nums[index] ){
                    count1++;
             }else if(majorityElement2 == nums[index] ){
                    count2++;
             }else{
                count1--;
                count2--;
             }
         }

         int majorityElement1Times = 0;
         int majorityElement2Times = 0;

        // store the result [all which appears more than n/3 times]
        vector<int> result;
        int threshold = nums.size() / 3;

         for(int index = 0; index < nums.size(); index++){
             if(nums[index] == majorityElement1)  majorityElement1Times ++;
             if(nums[index] == majorityElement2)  majorityElement2Times ++;
         }      

         // The majority element is the element that appears more than ⌊n / 3⌋ times.(all)
         if(majorityElement1Times > threshold){
            result.push_back(majorityElement1);
         }

         if(majorityElement2Times > threshold){
            result.push_back(majorityElement2);
         }
    
         return result;
    }
};

// Edge case [0,0,0] -> [0]
// ✅ best optimization code 
// i have fix it 

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

         int majorityElement1 = 0;
         int count1 = 0;

         int majorityElement2 = 0;
         int count2 = 0;

         for(int index = 0; index < nums.size(); index++){
           // assign new candidate using vote-1 
           // if next candidate is equal count++ otherwise count--
             if(count1 == 0 && majorityElement2 != nums[index]){
                count1 = 1;
                majorityElement1 = nums[index];
             }else if(count2 == 0 && majorityElement1 != nums[index]){
                count2 = 1;
                majorityElement2 = nums[index];
             }else if(majorityElement1 == nums[index] ){
                    count1++;
             }else if(majorityElement2 == nums[index] ){
                    count2++;
             }else{
                count1--;
                count2--;
             }
         }

         int majorityElement1Times = 0;
         int majorityElement2Times = 0;

        // store the result [all which appears more than n/3 times]
        vector<int> result;
        int threshold = nums.size() / 3;

         for(int index = 0; index < nums.size(); index++){
             if(nums[index] == majorityElement1)  majorityElement1Times ++;
             if(nums[index] == majorityElement2)  majorityElement2Times ++;
         }      

         // The majority element is the element that appears more than ⌊n / 3⌋ times.(all)
         if(majorityElement1Times > threshold){
            result.push_back(majorityElement1);
         }

         if(majorityElement2Times > threshold){
            result.push_back(majorityElement2);
         }

        // [0,0,0] -> (0)
        // Edges case we have to fix it
         int numberZeros = 0;
         for(int i = 0; i<result.size(); i++){
            if(result[i] == 0){
                numberZeros ++;
            }
         }     

         if(numberZeros > 1){
            return {0};
         }
         return result;
    }
};