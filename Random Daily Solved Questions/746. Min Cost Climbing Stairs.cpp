class Solution {
    vector<int> dp;
 private:
    int sol(vector<int>& cost,int n){
        if (n < 0) return 0;
        if (n==0 || n==1) return cost[n];
        return cost[n] + min(sol(cost, n-1), sol(cost, n-2));
    }
    
    
int TopDown(vector<int>& cost,int n){
    if (n < 0) return 0;
    if (n==0 || n==1) return cost[n];
    if (dp[n] != 0) return dp[n];
    dp[n] = cost[n] + min(TopDown(cost, n-1), TopDown(cost, n-2));
    return dp[n];
}
public:
    int minCostClimbingStairs(vector<int>& cost) {
    // -------------RECCURSION---------------
        // int n=cost.size();
        // return min(sol(cost,n-1),sol(cost,n-2));
    
    //----------Top Dowm DP-----------
        // int n=cost.size();
        // dp.resize(n,0);
        // return min(TopDown(cost,n-1),TopDown(cost,n-2));
        
    //----------Bottom UP DP-----------
        // int n=cost.size();
        // dp.resize(n,0);
        // for (int i=0; i<n; i++) {
        // 	if (i<2) dp[i] = cost[i];
        // 	else dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        // }
        // return min(dp[n-1], dp[n-2]);
        
    //---------DP WITH CONSTANT SPACE----------
        int n=cost.size();
        int a=cost[0],b=cost[1];
        if(n<=2) return min(a,b);
        for (int i=2; i<n; i++) {
        	int curr=cost[i]+min(a,b);
            a=b;
            b=curr;
        }
        return min(a,b);
    
    
    
    
    
    
    
    }
};
