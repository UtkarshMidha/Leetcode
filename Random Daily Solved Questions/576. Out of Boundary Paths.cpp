class Solution {
private:
int m,n;
int dp[50][50][51];
int direction[5] = {0, 1, 0, -1, 0};
    
    
int memo(int r, int c, int maxMove) {
        if (r < 0 || r == m || c < 0 || c == n) return 1; // Out of bound -> Count 1 way
        if (maxMove == 0) return 0;
        if (dp[r][c][maxMove] != -1) return dp[r][c][maxMove];
        int ans = 0;
        for (int i = 0; i < 4; ++i)
            ans = (ans + memo(r + direction[i], c + direction[i+1], maxMove - 1)) % 1000000007;
        return dp[r][c][maxMove] = ans;
    }
    
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
//         if (startRow == m || startColumn == n || startRow < 0 || startColumn < 0) return 1;
//         if (maxMove == 0) return 0;
        
        // return findPaths(m, n, maxMove - 1, startRow - 1, startColumn)
        //     + findPaths(m, n, maxMove - 1, startRow + 1, startColumn)
        //     + findPaths(m, n, maxMove - 1, startRow, startColumn - 1)
        //     + findPaths(m, n, maxMove - 1, startRow, startColumn + 1);
        this->m = m; this->n = n;
        memset(dp, -1, sizeof(dp));
        return memo(startRow, startColumn, maxMove);
    
    
    }
};
