class Solution {
public:
    char findTheDifference(string s, string t) {
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // int i=0;
        // for(char c :t){
        //     if (c!=s[i++])
        //         return c;
        // }
        // return 0;
        char c=0;
        for(char i:s) c^=i;
        for(char i:t) c^=i;
        return c;
    }
};
