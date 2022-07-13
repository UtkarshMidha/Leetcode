class Solution {
public:
    int fib(int n) {
     int a=0,b=1;
       if( n<2) return n;
        for(;n>1;n--){
         int sum=a+b;
         a=b;
         b=sum;
     }   
        return b;
    }
};
