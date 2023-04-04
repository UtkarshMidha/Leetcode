class Solution {
public:
    int partitionString(string s) {
       map<char,int> mp;
        int ans=1;
        mp[s[0]]++;
        for(int i=1;i<s.size();i++){
            if(mp[s[i]]){
                ++ans;
                mp.clear();
                mp[s[i]]++;
                
            } 
            else
            mp[s[i]]++;
        }
        return ans;
    }
};
