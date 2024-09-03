
//  Geek wants to climb from the 0th stair to the (n-1)th stair. At a time the Geek can climb either one or two steps. A height[N] array is also given. Whenever the geek jumps from stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]), where abs() means the absolute difference. return the minimum energy that can be used by the Geek to jump from stair 0 to stair N-1.
// Frog can jump 1 steps
// Frong can jump 2 steps 
// minimum costs need to reached 0 to stair N-1

// 📌 recurisive solution
class Solution {
  private:
    int helper(int index, vector<int> & height){
          
          if(index == 0){
              return 0;
          }
          
          //  the energy consumed in the jump is abs(height[i]- height[j]),
          //   Geek wants to climb from the 0th stair to the (n-1)th stair. 
          // At a time the Geek can climb either one or two steps.
          // Geek have 2 possible choices
          int oneJump = abs(height[index] - height[index-1] ) + helper(index-1,height);
          int twoJump;
          if(index > 1){
              twoJump = abs(height[index] - height[index-2]) + helper(index-2,height);
          }
          return min(oneJump,twoJump);
    }
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        int index = n - 1;
        return helper(index, height);
    }
};



// 📌 recurisive solution + memorization 

class Solution {
  private:
    int dp[100001];
    int helper(int index, vector<int> & height){
          
          if(index == 0){
              return 0;
          }
          
          if(dp[index] != -1){
              return dp[index];
          }
          
          //  the energy consumed in the jump is abs(height[i]- height[j]),
          //   Geek wants to climb from the 0th stair to the (n-1)th stair. 
          // At a time the Geek can climb either one or two steps.
          // Geek have 2 possible choices
          int oneJump = abs(height[index] - height[index-1] ) + helper(index-1,height);
          int twoJump = INT_MAX;
          if(index > 1){
              twoJump = abs(height[index] - height[index-2]) + helper(index-2,height);
          }
          return dp[index] = min(oneJump,twoJump);
    }
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        int index = n - 1;
        memset(dp,-1,sizeof(dp));
        return helper(index, height);
    }
};

// 📌 Tabulation code using [easy to undresand]

class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        int dp[n+1];
        dp[0] = 0;
        
        for(int index = 1;index < n; index++){
            
        int oneJump = abs(height[index] - height[index-1] ) + dp[index-1];
          int twoJump = INT_MAX;
          if(index > 1){
              twoJump = abs(height[index] - height[index-2]) + dp[index-2];
          }
           dp[index] = min(oneJump,twoJump);
        }
        return dp[n-1];
    }
};

// 📌 space optimization
// dp[i-1]
// dp[-2]
// we can just used Two variable, bacause, we need only two variable not entire dp array or vector

class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        int dp[n+1];
        
        int prev1= 0;
        int prev2 = 0;
        int curr = 0;
        
        for(int index = 1;index < n; index++){
            
        int oneJump = abs(height[index] - height[index-1] ) + prev1;
          int twoJump = INT_MAX;
          if(index > 1){
              twoJump = abs(height[index] - height[index-2]) + prev2;
          }
           curr = min(oneJump,twoJump);
           prev2 = prev1;
           prev1 = curr;
        }
        return prev1;
    }
};