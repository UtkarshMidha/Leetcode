class Solution {
public:
    string removeDuplicates(string s) {
        int i=0;
        for(int j=0;j<s.size();j++,++i){
            s[i]=s[j];
            if(i and s[i-1]==s[i])
                i-=2;
        }
        return s.substr(0,i);
    }
};
