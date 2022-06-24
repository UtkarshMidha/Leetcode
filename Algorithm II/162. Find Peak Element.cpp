class Solution {
public:
    int findPeakElement(vector<int>& nums) {
//         if(nums.size()==1) return 0;
//         int i=0;
        
//         while(i+1<nums.size() and nums[i]<nums[i+1])
//                 i++;
//         return i;   
    int l=0,r=nums.size()-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[mid+1])
                r=mid;
            else
                l=mid+1;
        }
        return l;
    
    }
};
