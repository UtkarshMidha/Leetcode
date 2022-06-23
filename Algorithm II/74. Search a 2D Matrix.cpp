class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size(),cols=matrix[0].size();
        int col=cols-1,row=0;
        while(row<rows and col>=0){
            int cur = matrix[row][col];
            if(matrix[row][col]==target ) return true;
            if (cur == target) return true;
                if (target > cur) row++;
                else col--;
            }
        return false;
    }
};
