

string findLCS(int n, int m,string &s1, string &s2){
	// Write your code here.	

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

	// len store the Lcs total Length of string
	int len = dp[n][m];

	string ans = "";

	for(int i=0;i<len;i++) ans+='$';

	int i = n;
	int j = m;

	int index = len - 1;

	while(i > 0 and j > 0){
		if(s1[i-1] == s2[j-1]){
			ans[index] = s1[i-1];
			index--;
			i--;
			j--;
        // and the basic of dp matrix move to store the next char
		}else if(dp[i-1][j] > dp[i][j-1]){
			i--;
		}else{
			j--;
		}
	}
	return ans;
}

