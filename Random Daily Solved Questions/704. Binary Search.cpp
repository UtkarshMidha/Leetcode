class Solution {
public:
    int search(vector<int>& nums, int target) {
       int i=0,j=nums.size();
        while(i<j){
            int mid=i+(j-i)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target)
                i=mid+1;
            else if(nums[mid]>target)
                j=mid;
                }
        return -1;
    }
};
