class Solution {
public:
    int climbStairs(int n) {
     //------RECCURSION--------
     //    if(n<2) return 1;
     // return climbStairs(n-1)+climbStairs(n-2)   ;
       
       //---------MEMORIZATION-----------
       // if(n<2) return 1;
       //  int arr[n+1];
       //  arr[0]=arr[1]=1;
       //  for(int i=2;i<=n;i++){
       //      arr[i]=arr[i-1]+arr[i-2];
       //  }
       //  return arr[n];
        
        if (n <= 1) {
            return n;
        }
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
