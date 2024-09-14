

// #1 recusive solution 
// #2 memorization (easy to write)
// #3 Table

class Solution {
  public:
    // Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string str1, string str2) {
        // your code here
        
        // step 1- declare the dp matrix using changable variable
        // step-2 copy the recurrence relations
        // step-3 convert into looping
        // step-4 base condtion 
        int dp[n+1][m+1];
        
        for(int i = 0; i<n+1; i++){
            for(int j = 0; j<m+1; j++){
                if(i == 0 or j == 0){
                    dp[i][j] = 0;
                }
            }
        }
        
        for(int i = 1; i<n+1; i++){
            for(int j = 1; j<m+1; j++){
                // Both char are matched or not matched 
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[n][m];
    }
};