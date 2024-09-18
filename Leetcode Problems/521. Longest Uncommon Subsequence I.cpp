class Solution {
public:
    int findLUSlength(string a, string b) {
        // dp on lcs
        int n = a.size();
        int m = b.size();
        int dp[n+1][m+1];
        for(int i = 0; i<n+1; i++){
            for(int j = 0; j<m+1; j++){
                if(i == 0 or j == 0){
                    dp[i][j] = 0;
                }else if(a[i-1] == b[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else if(a[i-1] != b[j-1]){
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int lcs = dp[n][m];
        // you got all common
        if(lcs == n && m == n){
            return -1;
        }else{
        // otherwise you got all uncommon, maximum(n,m) dono me kon hoga
        // bad problem hai ye 
            return max(m,n);
        }
    }
};