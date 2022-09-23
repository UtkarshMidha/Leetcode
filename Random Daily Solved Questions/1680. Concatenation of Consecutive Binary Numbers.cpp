class Solution {
private:
    int countOFbits(int n) {
		  return log2(n) + 1;
    }
public:
    int concatenatedBinary(int n) {
        const long MOD=1e9+7;
        long ans=0,len=0;
        for(int i=1;i<=n;i++){
            //int len=countOFbits(i);
            // OR :-
            if(__builtin_popcount(i) == 1) ++len; 
            //Count no. of bits set to 1
            //Count no. of set bit i.e. no. of bits having "1" is one 
            //This happens only in those numbers in power of 2  eg. 1,2,4,8,16
            ans=((ans<<len %MOD)+i)%MOD;
        }
        return (int)ans;        
    }
};
