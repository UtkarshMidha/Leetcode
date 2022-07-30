class Solution {
private:
    vector<int> freq_cal(string &s){
        vector<int> freq(26);
        for(char letter:s){
            freq[letter-'a']++;
        }
        return freq;
    }
public:
    
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        int word2_freq[26]={0};
      
        for(string &s:words2){
            vector<int> freq=freq_cal(s);
            for(int i=0;i<26;++i) word2_freq[i]=max(word2_freq[i],freq[i]);
        }
        
        for(string word:words1){
            vector<int> f=freq_cal(word);
            int i=0;
            
            for(;i<26;i++)
                if(f[i]<word2_freq[i])
                    break;
            
            if(i==26)
                ans.push_back(word);
        }
            return ans;
    }
};
