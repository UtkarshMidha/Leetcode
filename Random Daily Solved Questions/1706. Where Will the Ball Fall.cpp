class Solution {
public:
    vector<int> ans;
    vector<int> findBall(vector<vector<int>>& grid) 
    {
        if(empty(grid)) return {};
        
        int height = size(grid);
        int width = size(grid[0]);
        ans.resize(width,-1);
        
        int x_s = 0; //start column
        
        while(x_s<width)
        {
            int x = x_s; //starting position - column
            int y=0; //starting position - row
            for(;y<height;++y)
            {
                if( (x>=width || x<0) ||                          //outside range
                    (x == 0 && grid[y][x] == -1) ||              // condition / on left most column
                    (x ==width-1 && grid[y][x] == 1) ||          // condition \ on right most column
                    (grid[y][x] == -1 && grid[y][x-1] == 1) ||   // condition /, but \ on left column
                    (grid[y][x] == 1 && grid[y][x+1] == -1))      // condition \ on / on right  column
                {
                    break;
                }
                else if(grid[y][x] == 1) // move right
                {
                    x = x+1;
                }
                else if(grid[y][x] == -1) // move left
                {
                    x = x-1;
                }
            }
            if(y == height)
            {
                ans[x_s] = x;
            }
            x_s++; //move to next ball
        }
        return ans;
    }
};
