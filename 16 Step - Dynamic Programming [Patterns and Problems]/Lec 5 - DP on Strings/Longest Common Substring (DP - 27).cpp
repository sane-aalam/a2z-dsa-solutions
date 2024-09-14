class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
        // your code here
        
        int n = str1.size();
        int m = str2.size();
        
        int dp[n+1][m+1];
        
        for(int i = 0; i<n+1; i++){
            for(int j = 0; j<m+1; j++){
                if(i == 0 or j == 0){
                    dp[i][j] = 0;
                }
            }
        }

        // same to same happend - MajorityElement
        // break the chain, restart the process 
        int longestLength = 0;

        for(int i = 1; i<n+1; i++){
            for(int j = 1; j<m+1; j++){
                // Your task is to find the length of the longest common substring among the given string
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    longestLength = max(dp[i][j],longestLength);
                // restart the process 
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        return longestLength;
    }
};