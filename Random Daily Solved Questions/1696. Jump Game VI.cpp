class Solution {
private:
    int maxScore(int i, vector<int>& nums, int k, int n, vector<int>& dp) {
        
        if(i >= n)
            return -1e9;
        
        if(i == n-1)
            return nums[n-1];
        
        if(dp[i] != -1e9)
            return dp[i];
        
        int ans = -1e9;
        for(int j = 1; j <= k; j++) {
           
            ans = max(ans, nums[i] + maxScore(i + j, nums, k, n, dp));
        }
        
        return dp[i] = ans;
    }
public:    
    int maxResult(vector<int>& nums, int k) {
        
        int n = nums.size();
//         int i = 0;
        
//        vector<int> dp(n+1, -1e9);
//        return maxScore(i, nums, k, n, dp);
        
        vector<int> dp(n);
        deque<int> dq;
        dq.push_back(n-1);
        dp[n-1] = nums[n-1];
        
        for(int i = n - 2; i >= 0; i--) {
            
            if(i + k < dq.front())
                dq.pop_front();
            
            dp[i] += nums[i] + dp[dq.front()];
            while(!dq.empty() && dp[dq.back()] < dp[i])
                dq.pop_back();
            
            dq.push_back(i);
        }
        
        return dp[0];
    }
};
