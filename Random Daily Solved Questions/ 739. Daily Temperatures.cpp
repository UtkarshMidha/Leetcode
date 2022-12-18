class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) { 
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        stack<pair<int,int> > s;
        vector<int> ans(temperatures.size());
        for(int i = temperatures.size()-1;i>=0; i--)
        {
            auto curr = temperatures[i];
            while(!s.empty() && curr >= s.top().first)
            {
                s.pop();
            }           
            ans[i] = s.empty() ? 0: s.top().second - i; 
            s.push(pair<int, int>(temperatures[i], i));
        }
        return ans;
    }
};
