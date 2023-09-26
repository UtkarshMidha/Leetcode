class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnt(26,0), vis(26,0);
        string res = "";
        int n = s.size();
        for(auto c:s)
            cnt[c - 'a']++;
        
        for(int i = 0; i<n; ++i)
        {
            
            cnt[s[i] - 'a']--;
            
            
            if(!vis[s[i]- 'a'])
            {
                
                while(res.size()  and res.back() > s[i] and cnt[res.back() - 'a'] > 0)
                {
                    
                    vis[res.back() - 'a'] = 0;
                    res.pop_back();
                }
                
                
                res += s[i];
                vis[s[i] - 'a'] = 1;
            }
        }
      
        return res;
    }
};
