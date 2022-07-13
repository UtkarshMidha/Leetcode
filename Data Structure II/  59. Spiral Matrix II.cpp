class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> sol(n,vector<int>(n));
        int counter=1;
        for(int i=0;i<(n+1)/2;++i){
            for(int j=i;j<n-i;j++)
                sol[i][j]=counter++;
            
            for(int j=i+1;j<n-i;j++)
                sol[j][n-i-1]=counter++;
            
            for(int j=n-i-2;j>=i;j--)
                sol[n-i-1][j]=counter++;
            
            for(int j=n-i-2;j>i;j--)
                sol[j][i]=counter++;
        }
        return sol;
    }
};
