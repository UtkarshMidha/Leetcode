class Solution {
public:
    int minPartitions(string n) {
     char s='0';
        for(auto c:n){
            if(c=='9') return 9;
            if(c>s)
                s=c;
            }
        return  s-'0';
    }
};
