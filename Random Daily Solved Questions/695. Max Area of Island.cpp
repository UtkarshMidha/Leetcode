class Solution {
private:
    vector<vector<bool>> isvisited;
    
    int recc(int r,int c,vector<vector<int>> &grid){
       if(r<0 or c<0 or r>=grid.size() or c>=grid[0].size() or isvisited[r][c] or !grid[r][c])
           return 0;
        isvisited[r][c]=true;
        return (1+recc(r+1,c,grid)+recc(r,c+1,grid)+recc(r-1,c,grid)+recc(r,c-1,grid));
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        if (r==0) return 0;
        isvisited.resize(r,vector<bool>(c));
        int ans=0;
        for(int row=0;row<r;row++){
            for(int col=0;col<c;col++){
                if(isvisited[row][col]) 
                    continue;
                ans=max(ans,recc(row,col,grid));
            }
        }
        return ans;
    }
};
