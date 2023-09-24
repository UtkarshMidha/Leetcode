class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {

//2D dp        
//         vector<vector<double>> dp( 101 , vector<double> (101));
//         dp[0][0]=poured;
//         for(int i=0;i<100;i++){
//             for(int j=0;j<=i;j++){
//                 if(dp[i][j]>1){
//                     dp[i+1][j]+=(dp[i][j]-1)/2.0;
//                     dp[i+1][j+1]+=(dp[i][j]-1)/2.0;
//                     dp[i][j]=1;
//                 }
//             }
        
//         }
//         return dp[query_row][query_glass];
//  
        
// 1D dp
        vector<double>dp(101);
        dp[0]=poured;
        for(int row=1;row<=query_row;row++)
            for(int i=row;i>=0;i--)
                dp[i+1]+=dp[i]=max(0.0,(dp[i]-1)/2.0);
        return min(dp[query_glass],1.0);
        
    }
};
