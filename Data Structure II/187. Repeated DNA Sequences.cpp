class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if(size(s)<10) return ans;
        int n=size(s),i=0;
        unordered_map<string,int> mp;
        while(i+10<=n){
            mp[s.substr(i++,10)]++;
        }
        for(auto c:mp)
            if(c.second>1)
                ans.push_back(c.first);
    return ans;
    }
};
