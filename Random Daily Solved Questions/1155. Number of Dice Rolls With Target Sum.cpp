class Solution {
public:
vector<vector<int>>dp;
int helper(int n, int k, int rem){
     if(n<0||rem<0)
      return 0;
     
     if(dp[n][rem]!=-1)
        return dp[n][rem];
     
     if(rem==0&&n==0)
        return 1;
     
     if(n==0||rem==0)
        return 0;
     
     int count=0;
     for(int i=1;i<=k;i++)
        count=(count+(helper(n-1,k,rem-i)%1000000007))%1000000007;
     
 return dp[n][rem]=count;
}
    int numRollsToTarget(int n, int k, int target) {
     dp.resize(n+1,vector<int>(target+1,-1));
     return helper(n,k,target);   
    }
};
