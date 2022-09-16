class Solution {
private:
    vector<vector<int>> dp;
    
    int solver(int index,vector<int>& nums,vector<int>& multipliers,int start,int end){
        
        if(index==multipliers.size())
            return 0;
        
        if (dp[index][start]!=INT_MIN)
            return dp[index][start];
            
          int from_front = nums[start] * multipliers[index] + solver(index+1,nums, multipliers,start + 1, end );  
            
        
        int from_back = nums[end] * multipliers[index] + solver(index+1,nums, multipliers,start, end-1 );
        
        return dp[index][start]=max(from_front,from_back);
    }
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m=multipliers.size();
        dp.resize(m+1,vector<int>(m+1,INT_MIN));
        return solver(0,nums,multipliers,0,nums.size()-1);
    }
};
