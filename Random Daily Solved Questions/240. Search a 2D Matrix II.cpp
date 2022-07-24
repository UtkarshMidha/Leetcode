class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int rows=matrix.size(),row=0,col=matrix[0].size()-1;
        while(row<rows and col>=0){
            if(matrix[row][col]==target) return true;
            if(matrix[row][col]>target) col--;
            else row++;
        }
        return false;
    }
};

