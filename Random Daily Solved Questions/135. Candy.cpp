class Solution {
public:
    int candy(vector<int>& ratings) {
//------------O(N^2)-----TLE-----------
//         int n=size(ratings);
//         bool changed=true;
//         vector<int> dp (size(ratings),1);
//         while(changed){
//             changed=false;
            
//         for(int i=0;i<n;i++){
//             if(i!=n-1 and (ratings[i]>ratings[i+1]) and (dp[i]<=dp[i+1])){
//                 dp[i]=dp[i+1]+1;
//                 changed=true;
//             }
//             if(i>0 and ratings[i]>ratings[i-1] and dp[i]<=dp[i-1]){
//                 dp[i]=dp[i-1]+1;
//                 changed=true;
                
//             }
//         }
            
//         }
//         int ans=0;
//         for(int i=0;i<n;i++)
//             ans+=dp[i];
//         return ans;
        
        //--------------USING 2 ARRAYS AND LINEAR TIME
        int n=size(ratings);
        vector<int> left2right(n,1),right2left(n,1);
        
        for(int i=1;i<n;i++)
            if(ratings[i]>ratings[i-1])
                left2right[i]=left2right[i-1]+1;
        
        for(int i=n-2;i>=0;i--)
            if(ratings[i]>ratings[i+1])
                right2left[i]=right2left[i+1]+1;
        
        int sum=0;
        for(int i=0;i<n;i++)
           sum+=max(left2right[i],right2left[i]);
        
        return sum;
        
        
        
        
    }
};
