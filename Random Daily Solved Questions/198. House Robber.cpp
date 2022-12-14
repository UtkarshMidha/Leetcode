class Solution {
public:
    
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        int sol=0;
        if (nums.size()==0)return 0;
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=1;i<nums.size();i++){
            dp[i+1]=max(dp[i],dp[i-1]+nums[i]);
        }
        return dp[nums.size()];
        
    }
};
