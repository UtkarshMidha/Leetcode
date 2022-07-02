class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;
        int ans=0,unpaired=0;
        for(string s:words ){
            // If string has both characters same 
            if(s[0]==s[1]){
                // If pairs are there the can be used
                if(mp[s]>0)
                {   unpaired--;
                    mp[s]--;
                    ans+=4;
                }
                //Else if single i.e. unpaired then can be used as center
                else{
                    mp[s]++;
                    unpaired++;
                }
            }
            //If both caracters are not similar 
            else{
                //If reverse is in present 
            string rev=s;
            reverse(rev.begin(),rev.end());
                if(mp[rev]>0){
                    ans+=4;
                    mp[rev]--;
                }
                else
                    mp[s]++;
            }
        }
        if(unpaired) ans+=2;
        return ans;
    }
};
