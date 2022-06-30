class Solution {
public:
    int minMoves2(vector<int>& nums) {
         
        sort(nums.begin(),nums.end());
        
        if(nums.size()<2) 
            return 0;
        
        int n=nums.size(),ans=0,median=nums[n/2];
        for(int i=0;i<n;i++)
            ans+=abs(nums[i]-median);
        
        return ans;
        
    }
};
