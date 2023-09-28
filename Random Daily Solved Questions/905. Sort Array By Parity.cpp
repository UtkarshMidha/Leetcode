class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
     int high=nums.size()-1;
        int low=0;
        while(low<high){
            if(nums[low]%2==0)
                low++;
             else if(nums[high]%2!=0) 
                 high--;
            else if(nums[low]%2!=0 && nums[high]%2==0)
                swap(nums[low++],nums[high--]);
           
            
        }
    return nums;
    }
};
