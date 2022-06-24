class Solution {
public:
    int findMin(vector<int>& nums) {
        // O(n) approach 
        // int m=INT_MAX;
        // for(auto c:nums)
        //     m=min(m,c);
        // return m;
        
        // Binary Search
        if(nums.size()==1) return nums[0];
        int l=0,r=nums.size()-1;
        if(nums[r]>nums[0]) return nums[0];
            while(l<=r){
                int mid=l+(r-l)/2;
                if(nums[mid]>nums[mid+1])
                    return nums[mid+1];
                if(nums[mid]<nums[mid-1])
                    return nums[mid];
                if(nums[mid]>nums[0])
                    l=mid+1;
                else
                 r=mid-1;
                    
            }
        return -1;
    }
};
