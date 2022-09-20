class Solution {
public:

// //===========BRUTE FORCE===========
// //=====TC : O(3^(M + N))      SC:O(M+N)
// 	int ans = 0;
// 	int findLength(vector<int>& A, vector<int>& B) {
// 		solve(A, B, 0, 0);
// 		return ans;
// 	}
        
// 	int solve(vector<int>& A, vector<int>& B, int i, int j) {
// 		if(i >= size(A) || j >= size(B)) return 0;
// 		solve(A, B, i+1, j), solve(A, B, i, j+1);                   
// 		int common = A[i] == B[j] ? 1 + solve(A, B, i+1, j+1) : 0;  
// 		ans = max(ans, common);                                     
// 		return common;
// }

// //=============ITERATIVE METHOD===============
// //=========TC:O(M*N*min(M*N))  SC:O(1)========    
	// int findLength(vector<int>& A, vector<int>& B) {
	// 	int m = size(A), n = size(B), ans = 0;
	// 	for(int i = 0; i < m; i++) {
	// 		for(int j = 0; j < n; j++) {
	// 			int len = 0;
	// 			while(i + len < m and j + len < n and A[i+len] == B[j+len]) len++; 
	// 			ans = max(ans, len);  
	// 		}
	// 	}
	// 	return ans;
	// }

    
// //===================DP MEMORIZATION=============
	// vector<vector<int>>dp;
	// int ans = 0;
	// int findLength(vector<int>& A, vector<int>& B) {
	// 	dp.resize(size(A), vector<int>(size(B), -1));
	// 	solve(A, B, 0, 0);
	// 	return ans;
	// }
	// int solve(vector<int>& A, vector<int>& B, int i, int j) {
	// 	if(i >= size(A) || j >= size(B)) return 0;
	// 	if(dp[i][j] != -1) return dp[i][j];
	// 	solve(A, B, i+1, j), solve(A, B, i, j+1);
	// 	dp[i][j] = A[i] == B[j] ? solve(A, B, i+1, j+1) + 1 : 0;  
	// 	ans = max(ans, dp[i][j]);
	// 	return dp[i][j];
	// }
        
// //===========DP TABULATION=============
		// int findLength(vector<int>& A, vector<int>& B) {
		// int m = size(A), n = size(B), ans = 0, dp[m+1][n+1]; 
		// memset(dp, -1, sizeof dp);
		// for(int i = 0; i < m; i++) {
		// 	for(int j = 0, len = 0; j < n; j++) {
		// 		if(dp[i][j] == -1) {
		// 			while(i + len < m and j + len < n and A[i+len] == B[j+len]) len++;
		// // store the result for states (i, j) : 
		// 			// we know results for all states from (i, j) - (i+len, j+len)
		// 			while(len) dp[i + len][j + len] = len--;  
		// 		}
		// 		ans = max(ans, dp[i][j]);
		// 	}
		// }
		// return ans;
		// }
    
    
    //OPTIMIZED DP
    int findLength(vector<int>& A, vector<int>& B) {
            int m = size(A), n = size(B), ans = 0;
            int dp[m+1][n+1]; memset(dp, 0, sizeof dp);
            for(int i = 1; i <= m; i++) 
                for(int j = 1; j <= n; j++) 
                    dp[i][j] = A[i-1] == B[j-1] ? dp[i-1][j-1] + 1 : 0,
                    ans = max(ans, dp[i][j]);

            return ans;
        }
};
