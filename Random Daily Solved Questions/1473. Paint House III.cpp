class Solution {
private:
    vector<int> h;
    vector<vector<int>> c;
    //int dp[101][21][101];
    int dp[101][101][21];
    int M;
    int N;
    int Target;
    int helper(int i, int prevColor, int nbrs)
    {
        if(nbrs>Target)
            return INT_MAX/2;
        
        if(i==M)
            return nbrs==Target?0:INT_MAX/2;
        
        if(dp[i][prevColor][nbrs]!=-1)
            return dp[i][prevColor][nbrs];
        
        
        int ans = INT_MAX;
        if(h[i]==0)
            for(int j=0;j<N;j++)
                ans = min(ans, c[i][j] + helper(i+1, j+1, (j+1==prevColor)?nbrs:nbrs+1));
        else 
            ans = min(ans, helper(i+1,h[i], (h[i]==prevColor)?nbrs:nbrs+1));
        
        dp[i][prevColor][nbrs]=ans;
        return ans;
    }
    
    
    int dfs(vector<int>& houses, vector<vector<int>>& cost, int i, int target, int last_clr) {
    if (i >= houses.size() || target < 0)
        return target == 0 ? target : 1000001;
    if (houses[i] != 0) // painted last year.
        return dfs(houses, cost, i + 1, target - (last_clr != houses[i]), houses[i]);      
    if (dp[i][target][last_clr])
        return dp[i][target][last_clr];
    auto res = 1000001;
    for (auto clr = 1; clr <= cost[i].size(); ++clr) {
        res = min(res, cost[i][clr - 1] 
            + dfs(houses, cost, i + 1, target - (last_clr != clr), clr));
    }
        return dp[i][target][last_clr] = res;
}
    
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m , int n, int target) {
        h = houses;
        c = cost;
        M = m;
        N = n;
        Target=target;
        // memset(dp,-1,sizeof(dp));
        // int ans = helper(0,0,0);
        // return ans>=INT_MAX/2?-1:ans;
        int res= dfs(houses,cost,0,target,0);
        return res > 1000000 ? -1 : res;
    
    }
};
