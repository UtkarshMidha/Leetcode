class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,minn=INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            minn=min(minn,prices[i]);
            ans=max(ans,prices[i]-minn);
        }
    return ans;
    }
};
