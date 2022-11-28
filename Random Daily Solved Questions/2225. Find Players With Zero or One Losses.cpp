class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> mp;
            for(int i=0;i<matches.size();i++){
                mp[matches[i][1]]++;
            }
        vector<vector<int>> ans;
        vector<int> temp1,temp2;
        for(auto c:mp){
            if(c.second==0)
                temp1.push_back(c.first);
        
        else if(c.second==1)
            temp2.push_back(c.first);
    }
        for(auto c:matches){
            if(mp.find(c[0])==mp.end())
                temp1.push_back(c[0]);
        }
        set<int> s;
        for (int x : temp1)
            s.insert(x);
        temp1.clear();
        for(auto c:s)
            temp1.push_back(c);
    // ans.push_back(temp1);
    // ans.push_back(temp2);
        sort(temp1.begin(),temp1.end());
        sort(temp2.begin(),temp2.end());
        
    return {temp1,temp2};}
};
