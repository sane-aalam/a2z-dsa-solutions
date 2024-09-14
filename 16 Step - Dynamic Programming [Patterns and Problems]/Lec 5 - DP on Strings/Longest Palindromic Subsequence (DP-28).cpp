
// Longest Palindromic Subsequence (DP-28)
// using LCS

class Solution {
private:
    int lcs(string &s1, string &s2){

    int n = s1.size();
    int m = s2.size();
    
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
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
    return dp[n][m];
}
public:
    int longestPalindromeSubseq(string s) {
        string r = s;
        reverse(r.begin(),r.end());
        return lcs(s,r);
    }
};

Find square root of a number in log n
Find the Nth root of a number using binary search
Koko Eating Bananas
Minimum days to make M bouquets
Find the smallest Divisor
Capacity to Ship Packages within D Days
Kth Missing Positive Number
Aggressive Cows
Book Allocation Problem
Split array - Largest Sum
Painter's partition
Minimize Max Distance to Gas Station
Median of 2 sorted arrays
Kth element of 2 sorted arrays