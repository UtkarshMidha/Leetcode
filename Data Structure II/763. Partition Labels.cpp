class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> mp(26,0),ans;
        for(int i=0;i<s.size();i++) mp[s[i]-'a']=i;
        int maximumIndex=-1,lastIndex=0;
        for(int i=0;i<s.size();i++){
           maximumIndex=max(maximumIndex,mp[s[i]-'a']);
            if(maximumIndex==i){
                ans.push_back(maximumIndex-lastIndex+1);
                lastIndex=i+1;
            }
        }
        return ans;
    }
};
