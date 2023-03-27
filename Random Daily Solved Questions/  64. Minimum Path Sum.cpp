class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //vector<vector<int>>sol;
        int i=grid.size(),j=grid[0].size();
        
        for(int a=0;a<i;a++){
            for(int b=0;b<j;b++){
                if(a-1>=0 && b-1>=0 )
                    grid[a][b]+=min(grid[a-1][b],grid[a][b-1]);
                else if(a-1>=0)
                grid[a][b]+=grid[a-1][b];
                else if(b-1>=0)
                    grid[a][b]+=grid[a][b-1];
                    
            }
        }
    return grid[i-1][j-1];
    }
};
