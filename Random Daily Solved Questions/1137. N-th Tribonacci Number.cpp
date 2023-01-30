class Solution {
public:
    int tribonacci(int n) {
        // RECCURSION
        // if(n==1 || n==2) return 1;
        // else if(n==0) return 0;
        // return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
    // DP SOLUTION
       int a=0,b=1,c=1;
        if(n<=1) return n;
        for(;n>=3;n--){
            int d=a+b+c;
            a=b;
            b=c;
            c=d;
        }
        return c;
    }
};
