class Solution {
public:
    int minMoves2(vector<int>& nums) {
         
        sort(nums.begin(),nums.end());
        
        if(nums.size()<2) 
            return 0;
        // MEDIAN 
        // int n=nums.size(),ans=0,median=nums[n/2];
        // for(int i=0;i<n;i++)
        //     ans+=abs(nums[i]-median);
        // return ans;
        
        
        
//  --------------------USING DIFFERENCE FROM MID APPROACH :-----------------------
//         For nums [right], moves = nums [right] - nums [mid]
//         For nums [left], moves = nums [mid] - nums [left]
// Hence, adding the above 2 equations, we get:
//         Total Moves = nums [right] - nums [mid] + nums [mid] - nums [left]
//         Total Moves = nums [right] - nums [left]
        int n=nums.size(),mid=n/2,left=0,right=n-1,res=0;
        while(left<right)
            res+=nums[right--]-nums[left++];
        return res;
    }
};
