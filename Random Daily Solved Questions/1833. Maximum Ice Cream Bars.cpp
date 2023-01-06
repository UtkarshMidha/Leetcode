class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // // Time complexity: O(n⋅logn)
        // int ans=0,n=costs.size();
        // sort(costs.begin(),costs.end());
        // for(int i=0;i<n;++i)
        // {
        //     if(costs[i]>coins)
        //         return ans;
        //     ++ans;
        //     coins-=costs[i];
        // }
        // return ans;
        
        
       // // Time complexity: O(n+m) 
        int n = costs.size();
        int m = *max_element(costs.begin(), costs.end());
        int ans = 0;

        vector<int> freq(m + 1);
        for (auto& cost : costs) {
            freq[cost]++;
        }

        for (int cost = 1; cost <= m; ++cost) {
            if (!freq[cost]) {
                continue;
            }
            if (coins < cost) {
                break;
            }
            int count = min(freq[cost], coins / cost);
            coins -= cost * count;
            ans += count;
        }

        return ans; 
    }
};
