class Solution {
public:
    int minSteps(string s, string t) {
        int ans=0;
        int alphaCount[26]={0};
        for (int i=0;i<s.size();++i){
            alphaCount[s[i]-'a']++;
            alphaCount[t[i]-'a']--;
        }
        for (int val:alphaCount){
            ans+=max(0,val);
        }
        return ans;
    }
};
