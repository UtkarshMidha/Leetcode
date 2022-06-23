class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> ans(m*n);
        int u=0,d=m-1,l=0,r=n-1,p=0;
        while(u<=d && l<=r){
            for(int col=l;col<=r;col++){
                ans[p++]=matrix[u][col];
                }
            if(++u>d)
                break;
            for(int row=u;row<=d;row++){
                ans[p++]=matrix[row][r];
            }
            if(--r<l)
                break;
            for(int col=r;col>=l;col--){
                ans[p++]=matrix[d][col];
                }
            if(--d<u)
                break;
            
            for(int row=d;row>=u;row--){
                ans[p++]=matrix[row][l];
            }
            if (++l > r) 
                break;
            
        }
        
      return ans;  
    }
};
